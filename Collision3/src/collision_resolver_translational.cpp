#include "collision_resolver_translational.h"
#include "entity.h"
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "line.h"
#include "assert.h"
#include "corecrt_math_defines.h"

void CollisionResolverTranslational::resolveCollision(Entity* e1, Entity* e2)
{
  // u: velocity after collsion
  // v: velocity before collision
  // m : mass of entity
  // u1 = ((m1 - m2) / (m1 + m2)) * v1 + 2*m2 / (m1 + m2) * v2
  // u2 = ((m2 - m1) / (m2 + m1)) * v2 + 2*m1 / (m2 + m1) * v1
  static int breakpoint;
  Ball* ballE1 = dynamic_cast<Ball*>(e1);
  Ball* ballE2 = dynamic_cast<Ball*>(e2);
  if (ballE1 != nullptr || ballE2 != nullptr)
  {
    breakpoint++;
  }


  if (e1->getShapeType() == 1 && e2->getShapeType() == 1) //both are balls
  {
    sf::Vector2f v1 = e1->getVelocity();
    sf::Vector2f v2 = e2->getVelocity();
    float m1 = e1->getMass();
    float m2 = e2->getMass();
    
    sf::Vector2f u1 = ((m1 - m2) / (m1 + m2)) * v1 + 2 * m2 / (m1 + m2) * v2;
    sf::Vector2f u2 = ((m2 - m1) / (m2 + m1)) * v2 + 2 * m1 / (m2 + m1) * v1;

    e1->setVelocity(u1);
    e2->setVelocity(u2);
  }
  
  else if (e1->getShapeType() == 2 || e2->getShapeType() == 2) // one of them is a line, other must be ball
  {
    Ball* ball = nullptr;
    Line* line = nullptr;
    if (e1->getShapeType() == 1 && e2->getShapeType() == 2)  //e1 is a ball but e2 is a line
    {
      ball = dynamic_cast<Ball*> (e1);
      line = dynamic_cast<Line*> (e2);
    }
    else if (e1->getShapeType() == 2 && e2->getShapeType() == 1)  //e2 is a ball but e1 is a line
    {
      ball = dynamic_cast<Ball*> (e2);
      line = dynamic_cast<Line*> (e1);
    }
    else
    {
      assert(true);
    }
    
    // Get and calculate normal and directional vector of the collision surface
    line->getDirectionalVector();
    sf::Vector2f collisionNormalVector;
    collisionNormalVector.x = -1.0F * line->getDirectionalVector().y; 
    collisionNormalVector.y = line->getDirectionalVector().x;

    float angleOfNormalVector = -1.0F * atan2(collisionNormalVector.y, collisionNormalVector.x);  //should be relative to x coordinate, + directin with respect to clock.
    /*
    if (collisionNormalVector.y > 1e-5)
    {
      angleOfNormalVector = asin(collisionNormalVector.y / sqrt(collisionNormalVector.x * collisionNormalVector.x + collisionNormalVector.y * collisionNormalVector.y));
    }
    else
    {
      angleOfNormalVector = acos(collisionNormalVector.x / sqrt(collisionNormalVector.x * collisionNormalVector.x + collisionNormalVector.y * collisionNormalVector.y));
    }*/
    
    // Projection of the velocity vector to the normal vector of the collision surface
    float velocityProjectedToNormalVector = ball->getVelocity().x * collisionNormalVector.x + ball->getVelocity().y * collisionNormalVector.y;

    // Projection of the velocity vector to the directional vector of the collision surface
    float velocityProjectedToDirectionalVector = ball->getVelocity().x * line->getDirectionalVector().x + ball->getVelocity().y * line->getDirectionalVector().y;

    // Calculated new velocities in the new frame
    velocityProjectedToNormalVector *= -1.0F; // Reflects from surface
    velocityProjectedToDirectionalVector; // No change

    float lengthOfOriginalVelocity = sqrt(ball->getVelocity().x * ball->getVelocity().x + ball->getVelocity().y * ball->getVelocity().y);
    float lengthOfNewVelocity = sqrt(velocityProjectedToNormalVector * velocityProjectedToNormalVector + velocityProjectedToDirectionalVector * velocityProjectedToDirectionalVector);
    assert(lengthOfNewVelocity == lengthOfOriginalVelocity); // length of old and new velocity must be equal.

    float angleOfNewVelocityRelativeToNormalVector = atan2(velocityProjectedToDirectionalVector, velocityProjectedToNormalVector);
    /*
    if (velocityProjectedToDirectionalVector > 1e-5)
    {
      angleOfNewVelocityRelativeToNormalVector = asin(velocityProjectedToDirectionalVector / lengthOfNewVelocity);
    }
    else
    {
      angleOfNewVelocityRelativeToNormalVector = acos(velocityProjectedToNormalVector / lengthOfNewVelocity);
    }

    if (velocityProjectedToNormalVector > 0 && velocityProjectedToDirectionalVector > 0)
    {
      angleOfNewVelocityRelativeToNormalVector = angleOfNewVelocityRelativeToNormalVector;  //no change
    }
    else if (velocityProjectedToNormalVector < 0 && velocityProjectedToDirectionalVector > 0)
    {
      angleOfNewVelocityRelativeToNormalVector = M_PI - angleOfNewVelocityRelativeToNormalVector;
    }
    else if (velocityProjectedToNormalVector > 0 && velocityProjectedToDirectionalVector < 0)
    {
      angleOfNewVelocityRelativeToNormalVector = M_2_PI - angleOfNewVelocityRelativeToNormalVector;
    }
    else if (velocityProjectedToNormalVector < 0 && velocityProjectedToDirectionalVector < 0)
    {
      angleOfNewVelocityRelativeToNormalVector += M_PI;
    }
    */

    // Calculated new velocities in the world frame
    float newVelocityX = lengthOfNewVelocity * cos( angleOfNormalVector + angleOfNewVelocityRelativeToNormalVector);
    float newVelocityY = -1.0F * lengthOfNewVelocity * sin( angleOfNormalVector + angleOfNewVelocityRelativeToNormalVector);

    ball->setVelocity(sf::Vector2f(newVelocityX, newVelocityY));
  }

  else  //ball with rect, etc.
  {
    //TODO
  }
}
#include "collision_resolver_linear.h"
#include "entity.h"
#include <SFML/Graphics.hpp>
#include "ball.h"

void CollisionResolverLinear::resolveCollision(Entity* e1, Entity* e2)
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

  sf::Vector2f v1 = e1->getVelocity();
  sf::Vector2f v2 = e2->getVelocity();
  float m1 = e1->getMass();
  float m2 = e2->getMass();
  
  sf::Vector2f u1 = ((m1 - m2) / (m1 + m2)) * v1 + 2 * m2 / (m1 + m2) * v2;
  sf::Vector2f u2 = ((m2 - m1) / (m2 + m1)) * v2 + 2 * m1 / (m2 + m1) * v1;

  e1->setVelocity(u1);
  e2->setVelocity(u2);
}
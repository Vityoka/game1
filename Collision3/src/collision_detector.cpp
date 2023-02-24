#include "collision_detector.h"
#include <iostream>
#include <vector>
#include "ball.h"
#include "player.h"
#include "bricks.h"
#include "entity.h"

CollisionDetector::CollisionDetector()
{

}

CollisionDescriptor CollisionDetector::detectCollision(Ball& ball, Bricks& bricks)
{
  CollisionDescriptor collisionDescriptor;

  collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::NoCollision;
  collisionDescriptor.hitPosition = 0.0f; //not relevant for brick-ball collision

  for (std::vector<sf::RectangleShape>::iterator it = bricks.getShapes().begin(); it < bricks.getShapes().end(); it++)
  {
    if (ball.getBorderBottom() > it->getGlobalBounds().top &&
        ball.getBorderTop() < (it->getGlobalBounds().top + it->getGlobalBounds().height) &&
        ball.getBorderLeft() < (it->getGlobalBounds().left + it->getGlobalBounds().width) &&
        ball.getBorderRight() > it->getGlobalBounds().left
    )
    {
      //determine direction of collision. Currently only top-bottom direction is working.
      if (ball.getShape().getPosition().y > it->getPosition().y)
      {
        collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromBottom;
      }
      else
      {
        collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromTop;
      }
      //std::cout << "COLLISION \n";
      bricks.getShapes().erase(it);
    }
  }
  return collisionDescriptor;
}

CollisionDescriptor CollisionDetector::detectCollision(Ball& ball, Player& player)
{
  CollisionDescriptor collisionDescriptor;
  collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::NoCollision;

  if (ball.getBorderTop() < player.getBorderBottom() &&
      ball.getBorderBottom() > player.getBorderTop() &&
      ball.getBorderLeft() < player.getBorderRight() &&
      ball.getBorderRight() > player.getBorderLeft())
  {
    //determine direction of collision. Currently only top-bottom direction is working.
    if (ball.getShape().getPosition().y > player.getShape().getPosition().y)
    {
      collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromBottom;
    }
    else
    {
      collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromTop;
    }
    collisionDescriptor.hitPosition = (ball.getShape().getPosition().x - player.getShape().getPosition().x) / (player.getShape().getGlobalBounds().width / 2.0f);
    
    //we didnt calculate with a collision if ball's centerpoint is not hitting the player bar but the side of the ball does, therefore we bound hitPos between -1 and 1.
    if (collisionDescriptor.hitPosition > 1.0f)
    {
      collisionDescriptor.hitPosition = 1.0f;
    }
    else if (collisionDescriptor.hitPosition < -1.0f)
    {
      collisionDescriptor.hitPosition = -1.0f;
    }
  }
  return collisionDescriptor;
}

CollisionDescriptor CollisionDetector::detectCollision(Player& player, sf::Window& window)
{
  CollisionDescriptor collisionDescriptor;
  collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::NoCollision;

  if (player.getBorderLeft() < 0.0f)
  {
    collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromBottom;  //not ball!
  }
  if (player.getBorderRight() > window.getSize().x)
  {
    collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromBottom;  //not ball!
  }
  if (player.getBorderBottom() > window.getSize().y)
  {
    collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromBottom;  //not ball!
  }
  if (player.getBorderTop() < 0.0f)
  {
    collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromBottom;  //not ball!
  }
  return collisionDescriptor;
}

CollisionDescriptor CollisionDetector::detectAABBCollision(const std::vector<Entity*>& entities, Entity* thisEntity)
{
  CollisionDescriptor collisionDescriptor;
  collisionDescriptor.hitPosition = 0.0f;
  collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::NoCollision;

  for (auto entity : entities)
  {
    if (thisEntity == entity)
    { 
      // checking collision with itself is skipped
      continue;
    }
    if (entity->getShape().getGlobalBounds().intersects(thisEntity->getShape().getGlobalBounds()))
    {
      collisionDescriptor.collisionType = CollisionDescriptor::CollisionType::BallCollisionFromBottom;
      break;
    }
  }
  return collisionDescriptor;
}
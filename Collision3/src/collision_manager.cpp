#include "collision_manager.h"
#include "entity.h"

#include "ball.h"

void CollisionManager::manageCollisions(std::vector<Entity*>& entities, sf::Window& window, float deltaTime)
{
  for (Entity* entityUnderCheck : entities)
  {
    Ball * ballEntity = dynamic_cast<Ball*>(entityUnderCheck);
    static int breakpoint;
    if (ballEntity != nullptr)
    {
      breakpoint++; //helping debugging only. Code stops if entity is a ball.
    }

    for (Entity* otherEntity : entities)
    {
      if (otherEntity != entityUnderCheck)  //Skip collision detection with ourselves
      {
        bool wasCollision = m_collisionDetector.detectCollision(entityUnderCheck, otherEntity);
        if (wasCollision)
        {
          m_collisionResolver.resolveCollision(entityUnderCheck, otherEntity);
          // update other entity if it collided with entity under check
          otherEntity->update(window, deltaTime);
          // mark other entity updated, to not check again as "entity under check"
          otherEntity->setUpdateFlag();
          // If one collision has been detected we stop detecting. It is assumed that an entity can collide with only one other entity in a cycle.
          break;
        }
      }
    }
    // update entity under check regardless it had a collision or not
    entityUnderCheck->update(window, deltaTime);
  }

  for (auto entity : entities)
  {
    entity->resetUpdateFlag();
  }

}
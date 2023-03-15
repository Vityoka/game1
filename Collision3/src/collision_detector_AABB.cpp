#include "collision_detector_AABB.h"
#include "entity.h"
#include <SFML/Graphics.hpp>

bool CollisionDetectorAABB::detectCollision(const Entity* e1, const Entity* e2)
{
  //sf::Vector2f posE1 = e1->getPosition();
  //sf::Vector2f posE2 = e2->getPosition();

  bool isCollision = e1->getShape().getGlobalBounds().intersects(e2->getShape().getGlobalBounds());

  return isCollision;
}
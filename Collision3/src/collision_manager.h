#ifndef COLLISION_MANAGER_H_GUARD
#define COLLISION_MANAGER_H_GUARD

#include <vector>
#include "collision_detector_AABB.h"
#include "collision_resolver_translational.h"
#include <SFML/Window.hpp>

// forward declare
class Entity;

class CollisionManager
{
private:
  CollisionDetectorAABB m_collisionDetector;
  CollisionResolverTranslational m_collisionResolver;
public:
  void manageCollisions(std::vector<Entity*>& entities, sf::Window& window, float deltaTime);
};

#endif // COLLISION_MANAGER_H_GUARD
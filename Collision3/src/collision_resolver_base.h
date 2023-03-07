#ifndef COLLISION_RESOLVER_BASE_H_GUARD
#define COLLISION_RESOLVER_BASE_H_GUARD

// forward declare
class Entity;

class CollisionResolverBase
{
public:
  virtual void resolveCollision(Entity* e1, Entity* e2) = 0;
};

#endif // COLLISION_RESOLVER_BASE_H_GUARD
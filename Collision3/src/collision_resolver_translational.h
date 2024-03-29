#ifndef COLLISION_RESOLVER_TRANSLATIONAL_H_GUARD
#define COLLISION_RESOLVER_TRANSLATIONAL_H_GUARD

#include "collision_resolver_base.h"

class CollisionResolverTranslational : public CollisionResolverBase
{
public:
  void resolveCollision(Entity* e1, Entity* e2) override;
};

#endif // COLLISION_RESOLVER_TRANSLATIONAL_H_GUARD
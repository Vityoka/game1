#ifndef COLLISION_DETECTOR_AABB_H_GUARD
#define COLLISION_DETECTOR_AABB_H_GUARD

#include "collision_detector_base.h"

class CollisionDetectorAABB : public CollisionDetectorBase
{
public:
  bool detectCollision(const Entity* e1, const Entity* e2) override;
};

#endif // COLLISION_DETECTOR_AABB_H_GUARD
#ifndef COLLISION_DETECTOR_BASE_H_GUARD
#define COLLISION_DETECTOR_BASE_H_GUARD

// forward declare
class Entity;

class CollisionDetectorBase
{
public:
  virtual bool detectCollision(const Entity* e1, const Entity* e2) = 0;
};

#endif // COLLISION_DETECTOR_BASE_H_GUARD
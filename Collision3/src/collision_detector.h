#ifndef COLLISION_DETECTOR_H_GUARD
#define COLLISION_DETECTOR_H_GUARD

#include <SFML/Graphics.hpp>
#include <Vector>

//forward declaration
class Ball;
class Bricks;
class Player;
class Entity;

struct CollisionDescriptor
{
  enum CollisionType
  {
    NoCollision = 1,
    BallCollisionFromTop = 2,
    BallCollisionFromBottom = 3,
    BallCollisionFromLeft = 4,
    BallCollisionFromRight = 5
  };
  CollisionType collisionType;
  float hitPosition;  //0: center, -1.0: left edge, 1.0: right edge
};

class CollisionDetector
{
private:

public:
  CollisionDetector();
  static CollisionDescriptor detectCollision(Ball& ball, Bricks& bricks);
  static CollisionDescriptor detectCollision(Ball& ball, Player& player);
  static CollisionDescriptor detectCollision(Player& player, sf::Window& window);
  static CollisionDescriptor detectAABBCollision(const std::vector<Entity*>& entities, Entity* thisEntity);
};

#endif //COLLISION_DETECTOR_H_GUARD
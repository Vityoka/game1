#ifndef BALLCREATOR_H_GUARD
#define BALLCREATOR_H_GUARD

#include "entity_creator.h"
#include <vector>
#include <SFML/Graphics.hpp>

//forward declaration
class Entity;

class BallCreator : public EntityCreator
{
public:
  BallCreator() : EntityCreator() {};
  Entity* createProduct() override;
  Entity* createProduct(float radius, sf::Color color, sf::Vector2f shapePos);
  Entity* createRandomProduct(sf::Vector2i shapePos);
private:

};

#endif // BALLCREATOR_H_GUARD

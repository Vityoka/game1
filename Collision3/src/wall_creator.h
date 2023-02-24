#ifndef WALLCREATOR_H_GUARD
#define WALLCREATOR_H_GUARD

#include "entity_creator.h"
#include <vector>
#include <SFML/Graphics.hpp>

//forward declaration
class Entity;

class WallCreator : public EntityCreator
{
public:
    WallCreator() : EntityCreator() {};
    Entity* createProduct() override;
    Entity* createProduct(sf::Vector2f shapeSize, sf::Color color, sf::Vector2f shapePos);
    void generateInitialWalls(std::vector<Entity*>& entities);
private:

};

#endif // WALLCREATOR_H_GUARD

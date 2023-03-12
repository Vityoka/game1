#ifndef BRICKS_H_GUARD
#define BRICKS_H_GUARD

#include <SFML/Graphics.hpp>
#include <Vector>
#include "entity.h"

class Bricks : public Entity
{
private:
  std::vector<sf::RectangleShape> shapes;

  //float getBorderLeft(){return shape.getPosition().x - shapeSize.x / 2.0;}
  //float getBorderRight(){return shape.getPosition().x + shapeSize.x / 2.0;}
  //float getBorderTop(){return shape.getPosition().y - shapeSize.y / 2.0;}
  //float getBorderBottom(){return shape.getPosition().y + shapeSize.y / 2.0;}

public:
  Bricks();
  void update(sf::Window& window, float deltaTime);
  std::vector<sf::RectangleShape>& getShapes(){return shapes;}
  //const sf::RectangleShape& getShape(void) override;
};

#endif //BRICKS_H_GUARD
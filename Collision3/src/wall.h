#ifndef WALL_H_GUARD
#define WALL_H_GUARD

#include <SFML/Graphics.hpp>
#include "entity.h"

class Wall : public Entity
{
private:
  sf::RectangleShape shape;
  const sf::Vector2f defaultShapeSize = {50.0f, 50.0f};
public:
  Wall();
  Wall(sf::Vector2f shapeSize, sf::Color color, float posX, float posY);

  void calcNextPos(float deltaTime) override;
  void savePrevPos() override;
  void restorePos() override;
  const sf::Shape& getShape(void) const override;
  void update(sf::Window& window, float deltaTime) override;

  float getBorderLeft() const{return shape.getPosition().x - defaultShapeSize.x / 2.0;}
  float getBorderRight() const{return shape.getPosition().x + defaultShapeSize.x / 2.0;}
  float getBorderTop() const{return shape.getPosition().y - defaultShapeSize.y / 2.0;}
  float getBorderBottom() const{return shape.getPosition().y + defaultShapeSize.y / 2.0;}
};

#endif //WALL_H_GUARD
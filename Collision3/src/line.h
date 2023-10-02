#ifndef LINE_H_GUARD
#define LINE_H_GUARD

#include <SFML/Graphics.hpp>
#include "entity.h"

class Line : public Entity
{
private:
  sf::RectangleShape shape;
  //sf::Vertex line;
  const sf::Vector2f defaultShapeSize = {100.0f, 1.0f};
  sf::Vector2f directionalVector;
public:
  Line();
  Line(sf::Vector2f shapeSize, sf::Color color, float posX, float posY, float rot);

  const sf::Shape& getShape(void) const override;
  void calcNextPos(float deltaTime) override;
  void savePrevPos() override;
  void restorePos() override;
  
  void update(sf::Window& window, float deltaTime) override;
  sf::Vector2f getDirectionalVector(){return directionalVector;};

};

#endif //LINE_H_GUARD
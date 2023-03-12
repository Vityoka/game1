#ifndef PLAYER_H_GUARD
#define PLAYER_H_GUARD

#include <SFML/Graphics.hpp>
#include "entity.h"

constexpr float offsetXDebug = 200.0f;
constexpr float playerInitPosX = 400.0f - offsetXDebug;
constexpr float playerInitPosY = 550.0f;

class Player : public Entity
{
private:
  sf::RectangleShape shape;
  const sf::Vector2f shapeSize = {50.0f, 50.0f};

  void calcNextPos(float deltaTime) override;
  void savePrevPos() override;
  void restorePos() override;

public:
  Player();
  void update(sf::Window& window, float deltaTime) override;
  const sf::Shape& getShape() override {return shape;}

  float getBorderLeft() const{return m_position.x - shapeSize.x / 2.0;}
  float getBorderRight() const{return m_position.x + shapeSize.x / 2.0;}
  float getBorderTop() const{return m_position.y - shapeSize.y / 2.0;}
  float getBorderBottom() const{return m_position.y + shapeSize.y / 2.0;}
};

#endif //PLAYER_H_GUARD
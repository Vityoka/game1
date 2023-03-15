#ifndef BALL_H_GUARD
#define BALL_H_GUARD

#include "entity.h"
#include <SFML/Graphics.hpp>

//forward declaration
enum GameState: char;

constexpr float ballVelocity = 500.0f;
constexpr float ballRadius = 10.0f;
constexpr float ballInitPostionX = 400.0f;
constexpr float ballInitPostionY = 535.0f;
constexpr float ballMass = 10.0f;


class Ball : public Entity
{
private:

  sf::CircleShape shape;
  const sf::Vector2f shapeSize = { 50.0f, 50.0f };

public:
  Ball();
  Ball(sf::Vector2f shapeSize, sf::Color color, float posX, float posY);
  Ball(sf::Vector2f shapeSize, sf::Color color, float posX, float posY, sf::Vector2f velocity);

  void calcNextPos(float deltaTime) override;
  void savePrevPos() override;
  void restorePos() override;

  const sf::Shape& getShape() const override { return shape; }

  //void update(float deltaTime);
  void update(sf::Window& window, float deltaTime) override;

  float getBorderLeft() const{return m_position.x - ballRadius;}
  float getBorderRight() const{return m_position.x + ballRadius;}
  float getBorderTop() const{return m_position.y - ballRadius;}
  float getBorderBottom() const{return m_position.y + ballRadius;}

};

#endif //BALL_H_GUARD
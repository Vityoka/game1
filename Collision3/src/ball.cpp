#include "ball.h"
#include <SFML/Graphics.hpp>
#include "player.h"
#include <cmath>
#include "game.h"
#include <cstdlib>   // rand and srand
#include <ctime> 

Ball::Ball()  
{
	float intialStartDeviation = -0.2f; //should be randomized

  m_mass = ballMass;
  m_position.x = ballInitPostionX;
  m_position.y = ballInitPostionY;
  m_velocity.x = intialStartDeviation * ballVelocity;
  m_velocity.y = - sqrt(ballVelocity * ballVelocity - m_velocity.x * m_velocity.x);
  shape.setRadius(ballRadius);
  shape.setFillColor(sf::Color::Green);
  shape.setOrigin(ballRadius, ballRadius);
  shape.setPosition(m_position.x, m_position.y);
}


Ball::Ball(sf::Vector2f shapeSize, sf::Color color, float posX, float posY)
{
  m_position.x = posX;
  m_position.y = posY;
  shape.setRadius(shapeSize.x);
  shape.setFillColor(sf::Color::Green);
  shape.setOrigin(shapeSize.x, shapeSize.x);
  shape.setPosition(m_position.x, m_position.y);
}

Ball::Ball(sf::Vector2f shapeSize, sf::Color color, float posX, float posY, sf::Vector2f velocity)
{
  m_position.x = posX;
  m_position.y = posY;
  shape.setRadius(shapeSize.x);
  shape.setFillColor(sf::Color::Green);
  shape.setOrigin(shapeSize.x, shapeSize.x);
  shape.setPosition(m_position.x, m_position.y);
  m_velocity = velocity;
}


void Ball::calcNextPos(float deltaTime)
{
  /*temporary solution for bouncing off from walls until collision with walls is solved*/
  if (getBorderLeft() < 0.0f)
  {
    m_velocity.x *= -1.0f;
  }
  if (getBorderRight() > 800)
  {
    m_velocity.x *= -1.0f;
  }
  if (getBorderBottom() > 600)
  {
    m_velocity.y *= -1.0f;
  }
  if (getBorderTop() < 0)
  {
    m_velocity.y *= -1.0f;
  }

  m_position.x += m_velocity.x * deltaTime;
  m_position.y += m_velocity.y * deltaTime;
}

void Ball::savePrevPos()
{
  m_prevPosition.x = m_position.x;
  m_prevPosition.y = m_position.y;
}

void Ball::restorePos()
{
  m_position.x = m_prevPosition.x;
  m_position.y = m_prevPosition.y;
}

void Ball::update(sf::Window& window, float deltaTime)
{
  if (!m_wasUpdated)
  {
    calcNextPos(deltaTime);
    shape.setPosition(m_position.x, m_position.y);
  }
  m_wasUpdated = true;
}
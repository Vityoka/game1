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

  m_posX = ballInitPostionX;
  m_posY = ballInitPostionY;
  velocity.x = intialStartDeviation * ballVelocity;
  velocity.y = - sqrt(ballVelocity * ballVelocity - velocity.x * velocity.x);
  shape.setRadius(ballRadius);
  shape.setFillColor(sf::Color::Green);
  shape.setOrigin(ballRadius, ballRadius);
  shape.setPosition(m_posX, m_posY);
}


Ball::Ball(sf::Vector2f shapeSize, sf::Color color, float posX, float posY)
{
  m_posX = posX;
  m_posY = posY;
  shape.setRadius(shapeSize.x);
  shape.setFillColor(sf::Color::Green);
  shape.setOrigin(shapeSize.x, shapeSize.x);
  shape.setPosition(m_posX, m_posY);
}


void Ball::calcNextPos(float deltaTime)
{
  m_posX += velocity.x * deltaTime;
  m_posY += velocity.y * deltaTime;
}

void Ball::savePrevPos()
{
  m_prevPosX = m_posX;
  m_prevPosY = m_posY;
}

void Ball::restorePos()
{
  m_posX = m_prevPosX;
  m_posY = m_prevPosY;
}

void Ball::update(sf::Window& window)
{
  shape.setPosition(m_posX, m_posY);
}
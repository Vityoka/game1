#include "player.h"
#include <iostream>

Player::Player()
{
  shapeType = 0;
  m_position.x = playerInitPosX;
  m_position.y = playerInitPosY;
  shape.setSize(shapeSize);
  shape.setFillColor(sf::Color::Red);
  shape.setOrigin(shapeSize.x / 2.0f, shapeSize.y / 2.0f);
  shape.setPosition(m_position.x, m_position.y);
}

void Player::calcNextPos(float deltaTime)
{
  const float speed = 5.0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    m_position.x -= speed; 
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    m_position.x += speed; 
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    m_position.y += speed; 
  } 
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    m_position.y -= speed; 
  }
}

void Player::savePrevPos()
{
  m_prevPosition.x = m_position.x;
  m_prevPosition.y = m_position.y;
}

void Player::restorePos()
{
  m_position.x = m_prevPosition.x;
  m_position.y = m_prevPosition.y;
}

void Player::update(sf::Window& window, float deltaTime)
{
  if (!m_wasUpdated)
  {
    calcNextPos(deltaTime);
    shape.setPosition(m_position.x, m_position.y);
  }
}
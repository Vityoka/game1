#include "player.h"
#include <iostream>

Player::Player()
{
  m_posX = playerInitPosX;
  m_posY = playerInitPosY;
  shape.setSize(shapeSize);
  shape.setFillColor(sf::Color::Red);
  shape.setOrigin(shapeSize.x / 2.0f, shapeSize.y / 2.0f);
  shape.setPosition(m_posX, m_posY);
}

void Player::calcNextPos(float deltaTime)
{
  const float speed = 5.0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    m_posX -= speed; 
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    m_posX += speed; 
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    m_posY += speed; 
  } 
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    m_posY -= speed; 
  }
}

void Player::savePrevPos()
{
  m_prevPosX = m_posX;
  m_prevPosY = m_posY;
}

void Player::restorePos()
{
  m_posX = m_prevPosX;
  m_posY = m_prevPosY;
}

void Player::update(sf::Window& window)
{
  shape.setPosition(m_posX, m_posY);
}
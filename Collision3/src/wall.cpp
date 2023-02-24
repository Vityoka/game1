#include "wall.h"

constexpr float wallInitPosX = 400.0f;
constexpr float wallInitPosY = 550.0f;

Wall::Wall()
{
  m_posX = wallInitPosX;
  m_posY = wallInitPosY;
  shape.setSize(shapeSize);
  shape.setFillColor(sf::Color::Red);
  shape.setOrigin(shapeSize.x / 2.0f, shapeSize.y / 2.0f);
  shape.setPosition(m_posX, m_posY);
}

Wall::Wall(sf::Vector2f shapeSize, sf::Color color, float posX = wallInitPosX, float posY = wallInitPosY)
{
  m_posX = posX;
  m_posY = posY;
  shape.setSize(shapeSize);
  shape.setFillColor(color);
  shape.setOrigin(shapeSize.x / 2.0f, shapeSize.y / 2.0f);
  shape.setPosition(m_posX, m_posY);
}


void Wall::calcNextPos( float deltaTime )
{

}

void Wall::savePrevPos()
{
  m_prevPosX = m_posX;
  m_prevPosY = m_posY;
}

void Wall::restorePos()
{
  m_posX = m_prevPosX;
  m_posY = m_prevPosY;
}

const sf::Shape& Wall::getShape(void)
{
    return shape;
}

void Wall::update(sf::Window& window)
{

}
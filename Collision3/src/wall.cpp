#include "wall.h"

constexpr float wallInitPosX = 150.0f;
constexpr float wallInitPosY = 550.0f;

Wall::Wall()
{
  m_position.x = wallInitPosX;
  m_position.y = wallInitPosY;
  shape.setSize(defaultShapeSize);
  shape.setFillColor(sf::Color::Blue);
  shape.setOrigin(defaultShapeSize.x / 2.0f, defaultShapeSize.y / 2.0f);
  shape.setPosition(m_position.x, m_position.y);
}

Wall::Wall(sf::Vector2f shapeSize, sf::Color color, float posX = wallInitPosX, float posY = wallInitPosY)
{
  m_position.x = posX;
  m_position.y = posY;
  shape.setSize(shapeSize);
  shape.setFillColor(color);
  shape.setOrigin(shapeSize.x / 2.0f, shapeSize.y / 2.0f);
  shape.setPosition(m_position.x, m_position.y);
}


void Wall::calcNextPos( float deltaTime )
{

}

void Wall::savePrevPos()
{
  m_prevPosition.x = m_position.x;
  m_prevPosition.y = m_position.y;
}

void Wall::restorePos()
{
  m_position.x = m_prevPosition.x;
  m_position.y = m_prevPosition.y;
}

const sf::Shape& Wall::getShape(void) const
{
    return shape;
}

void Wall::update(sf::Window& window, float deltaTime)
{
  if (!m_wasUpdated)
  {
    //calcNextPos(deltaTime);
    //shape.setPosition(m_position.x, m_position.y);
  }
}
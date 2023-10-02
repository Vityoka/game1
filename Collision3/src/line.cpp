#include "line.h"
#include "corecrt_math_defines.h"

constexpr float lineInitPosX = 150.0f;
constexpr float lineInitPosY = 550.0f;

Line::Line()
{
  isStaticFlag = true;
  shapeType = 2;
  m_position.x = lineInitPosX;
  m_position.y = lineInitPosY;
  shape.setSize(defaultShapeSize);
  shape.setFillColor(sf::Color::White);
  shape.setOrigin(defaultShapeSize.x / 2.0f, defaultShapeSize.y / 2.0f);
  shape.setPosition(m_position.x, m_position.y);
  directionalVector.x = defaultShapeSize.x;
  directionalVector.y = defaultShapeSize.y;
}

Line::Line(sf::Vector2f shapeSize, sf::Color color, float posX, float posY, float rot)
{
  shapeSize.y = 1.0F;
  shapeType = 2;
  isStaticFlag = true;
  m_position.x = posX;
  m_position.y = posY;
  shape.setSize(shapeSize);
  shape.setFillColor(color);
  shape.setOrigin(shapeSize.x / 2.0f, shapeSize.y / 2.0f);
  shape.setPosition(m_position.x, m_position.y);
  shape.rotate(rot);
  directionalVector.x = defaultShapeSize.x * cos(rot * M_PI / 180.0F );
  directionalVector.y = defaultShapeSize.y * sin(rot * M_PI / 180.0F );
  float lenDirectionalVector = sqrt(directionalVector.x * directionalVector.x + directionalVector.y * directionalVector.y);
  directionalVector.x /= lenDirectionalVector;
  directionalVector.y /= lenDirectionalVector;
}


void Line::calcNextPos( float deltaTime )
{

}

void Line::savePrevPos()
{
  m_prevPosition.x = m_position.x;
  m_prevPosition.y = m_position.y;
}

void Line::restorePos()
{
  m_position.x = m_prevPosition.x;
  m_position.y = m_prevPosition.y;
}

void Line::update(sf::Window& window, float deltaTime)
{
  if (!m_wasUpdated)
  {
    //calcNextPos(deltaTime);
    //shape.setPosition(m_position.x, m_position.y);
  }
}

const sf::Shape& Line::getShape(void) const
{
    return shape;
}
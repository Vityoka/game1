#include "ball_creator.h"
#include <random>
#include "ball.h"
#include <iostream>
#include <cmath>

Entity* BallCreator::createProduct()
{
  Entity* p_Product = new Ball();
  return p_Product;
}

Entity* BallCreator::createProduct(float radius, sf::Color color, sf::Vector2f shapePos)
{
  sf::Vector2f shapeSize {radius, radius};
  Entity* p_Product = new Ball(shapeSize, color, shapePos.x, shapePos.y);
  return p_Product;
}

Entity* BallCreator::createRandomProduct(sf::Vector2i shapePos)
{
  std::random_device rd;
  std::uniform_real_distribution <float> distribution(0.0f, 1.0f);
  std::uniform_real_distribution <float> distributionForVelocityMagnitude(200.0f, 400.0f);
  std::uniform_real_distribution <float> distributionForVelocityAngle(0.0f, 6.28f);

  float radius = distribution(rd);
  sf::Vector2f shapeSize{ 5 + radius*5 , 5 + radius*5 };
  sf::Color color = sf::Color::Green;

  float velocityMagnitude = distributionForVelocityMagnitude(rd);
  float velocityAngle = distributionForVelocityAngle(rd);
  sf::Vector2f velocity { velocityMagnitude*cos(velocityAngle) , velocityMagnitude*sin(velocityAngle) };

  Entity* p_Product = new Ball(shapeSize, color, static_cast<float>(shapePos.x), static_cast<float>(shapePos.y), velocity);
  return p_Product;
}
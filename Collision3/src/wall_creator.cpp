#include "wall_creator.h"
#include "wall.h"
#include <random>
#include <iostream>

Entity* WallCreator::createProduct()
{
  Entity* p_Product = new Wall();
  return p_Product;
}

Entity* WallCreator::createProduct(sf::Vector2f shapeSize, sf::Color color, sf::Vector2f shapePos)
{
  Entity* p_Product = new Wall(shapeSize, color, shapePos.x, shapePos.y);
  return p_Product;
}


void WallCreator::generateInitialWalls(std::vector<Entity*>& entities)
{
  std::random_device rd;
  std::uniform_real_distribution <float> distribution(0.0f, 1.0f);

  float minHeight = 10.0f;
  float minWidth = 10.0f;
  float startPosX = 0.0;
  float startPosY = 0.0;
  bool wasCollison = false;

  // Generate walls with random size and position within window borders and without intersecting each other
  for (int i = 0; i < 20; i++)
  {
    wasCollison = false;
    sf::Vector2f shapeSize = { distribution(rd) * 30.0f + minWidth, distribution(rd) * 30.0f + minHeight };
    sf::Vector2f shapePos = { distribution(rd) * 800.0f, distribution(rd) * 600.0f };

    Entity* newWall = createProduct(shapeSize, sf::Color::Blue, shapePos);

    for (int j = 0; j < entities.size(); j++)
    {
      if (entities[j]->getShape().getGlobalBounds().intersects(newWall->getShape().getGlobalBounds()))
      {
          wasCollison = true;
          i--;
          break;
      }
    }
    if (!wasCollison)
    {
      entities.push_back(newWall);
    }
  }
}

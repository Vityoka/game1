#include "bricks.h"
#include <random>
#include <iostream>

const float windowSizeX = 800;
const float windowSizeY = 600;

const float brickWidth = 80.0f;
const float gapBetweenBricksX = 10.0f;
const float gapBetweenBricksY = 10.0f;
const float brickHeight = 30.0f;
const sf::Vector2f shapeSize = {brickWidth - gapBetweenBricksX, brickHeight - gapBetweenBricksY};

Bricks::Bricks()
{ 
	std::random_device rd;
	std::uniform_real_distribution <float> distribution(0.0f, 1.0f);

	float minHeight = 10.0f;
	float minWidth = 10.0f;
	float startPosX = 0.0;
	float startPosY = 0.0;
	bool wasCollison = false;

  // Generate bricks with random size and position within window borders and without intersecting each other
	for (int i = 0; i < 20; i++)
	{
		int asd = shapes.size();
		sf::Vector2f shapeSize = { distribution(rd) * 30.0f + minWidth, distribution(rd) * 30.0f + minHeight };
		sf::Vector2f shapePos = { distribution(rd) * 800.0f, distribution(rd) * 600.0f };
		sf::RectangleShape newShape(shapeSize);
		newShape.setOrigin(shapeSize.x / 2.0f, shapeSize.y / 2.0f);
		newShape.setPosition(shapePos);

		for (int j = 0; j < shapes.size(); j++)
		{
			if (shapes[j].getGlobalBounds().intersects(newShape.getGlobalBounds()))
			{
				wasCollison = true;
				i--;
				break;
			}
		}
		if (!wasCollison)
		{
			newShape.setFillColor(sf::Color::Yellow);
			shapes.push_back(newShape);
		}
	}
}

void Bricks::update(sf::Window& window, float deltaTime)
{

}
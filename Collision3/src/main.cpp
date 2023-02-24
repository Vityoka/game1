//#define SFML_STATIC   //enable define for static linkage of dependencies

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ball.h"
#include "player.h"
#include "bricks.h"
#include "collision_detector.h"

#include "game.h"

int main()
{
  // create window and game
  sf::RenderWindow window(sf::VideoMode(800, 600), "CollsionSim");
  window.setFramerateLimit(60);
  
  Game game(window);

  while(game.isRunning())
  {
    game.update();
    game.render();
  }

  return 0;
}
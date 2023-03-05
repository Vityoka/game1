#ifndef GAME_H_GUARD
#define GAME_H_GUARD

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ball.h"
#include "player.h"
#include "wall.h"
#include "collision_detector.h"

enum GameState : char{
  GAME_INIT = 0,
  GAME_RUNNING = 1,
  GAME_OVER = 2
};

class Game
{
public:
  Game(sf::RenderWindow& window);
  void init();
  void updateNormal();
  void update();
  void render();
  bool isRunning() const;

private:
  sf::Event m_event;
  sf::RenderWindow& m_window;

  sf::Clock m_clock;
  float m_deltaTime;

  CollisionDetector m_collisionDetector;

  std::vector<Entity*> m_entities;

  sf::SoundBuffer m_soundBufferBallBrickCollision;
  sf::SoundBuffer m_soundBufferBallPlayerCollision;
  sf::Sound m_sound;
  sf::Music m_music;
  sf::Text m_textGameOver;
  sf::Font m_font;

  GameState m_gameState;

  void pollEvents();

};

#endif //GAME_H_GUARD
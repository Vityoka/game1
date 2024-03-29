#include "game.h"
#include "wall_creator.h"
#include "ball_creator.h"


Game::Game(sf::RenderWindow& window) : m_window(window)
{
  init();
}

void Game::init()
{
  m_gameState = GameState::GAME_RUNNING;
  if (!m_soundBufferBallBrickCollision.loadFromFile("./res/audio/explosion.wav"))
  {
    std::cout << "Error loading file audio/explosion.wav\n";
  }
  if (!m_soundBufferBallPlayerCollision.loadFromFile("./res/audio/HitHurt.wav"))
  {
    std::cout << "Error loading file audio/HitHurt.wav\n";
  }
  if (!m_music.openFromFile("./res/audio/arkanoidMusic.ogg"))
  {
    std::cout << "Error loading file audio/arkanoidMusic.ogg\n";
  }
  else
  {
    //m_music.play();
  }
  if (!m_font.loadFromFile("./res/font/ThereBrat.ttf"))
  {
    std::cout << "error loading font\n";
  }
  else
  {
    m_textGameOver.setFont(m_font);
    m_textGameOver.setFillColor(sf::Color::White);
    m_textGameOver.setString("Game over");
    m_textGameOver.setScale(2.0, 2.0);
    m_textGameOver.setPosition(m_window.getSize().x/2.0 - 130.0, m_window.getSize().y/2.0 - 40);
  }

  //Create entities

  //Player* p_player = new Player();
  //m_entities.push_back(p_player);

  //Wall* p_wall = new Wall();
  //m_entities.push_back(p_wall);
  WallCreator wallCreator;
  //Entity* p_wall = wallCreator.createProduct();
  //m_entities.push_back(p_wall);
  //p_wall = wallCreator.createProduct({ 50.0, 50.0 }, sf::Color::Blue, {500, 200});
  //m_entities.push_back(p_wall);
  wallCreator.generateInitialWalls(m_entities);

  Ball* p_ball = new Ball();
  m_entities.push_back(p_ball);

}

bool Game::isRunning() const
{
  return m_window.isOpen();
}

void Game::pollEvents()
{
  // check all the window's events that were triggered since the last iteration of the loop
  while (m_window.pollEvent(m_event))
  {
    switch(m_event.type)
    {
      // "close requested" event: we close the window
      case sf::Event::Closed:
      {
        m_window.close();
        break;
      }
      case sf::Event::MouseButtonPressed:
      {
        BallCreator ballCreator;
        m_entities.push_back(ballCreator.createRandomProduct(sf::Mouse::getPosition(m_window)));

        if (m_gameState == GameState::GAME_INIT)
        {
          m_gameState = GameState::GAME_RUNNING;
        }
        break;
      }
    }
  }
}

void Game::render()
{
  //clear window
  m_window.clear(sf::Color::Black);

  //draw onto window
  switch(m_gameState)
  {
    case GameState::GAME_INIT:
    case GameState::GAME_RUNNING:
    {
      for (auto& entity : m_entities)
      {
          m_window.draw(entity->getShape());
      }
      break;
    }
    case GameState::GAME_OVER:
    {
      m_window.draw(m_textGameOver);
      break;
    }
  }
  //display window
  m_window.display();
}

void Game::update()
{
  // Time control. Currently overriden with constant to support debugging.
  //m_deltaTime = m_clock.restart().asSeconds();  
  //std::cout << m_deltaTime << std::endl;
  m_deltaTime = 0.017;  // if real clock is used than in debug mode breakpoint sets infinite time and everything falls apart.

  m_window.clear(sf::Color::Black);
  pollEvents();

  switch(m_gameState)
  {
    case GAME_INIT:
    {
      break;
    }
    case GAME_RUNNING:
    {
      updateNormal();
      break;
    }
    case GAME_OVER:
    {
      break;
    }
  }
}


void Game::updateNormal()
{
  m_collisionManager.manageCollisions(m_entities, m_window, m_deltaTime);

  /*
  for (auto entity : m_entities)
  {

    Ball* ballEntity = dynamic_cast<Ball*>(entity);
    static int breakpoint;
    if (ballEntity != nullptr)
    {
      breakpoint++; //helping debugging only. Code stops if entity is a ball.
    }

    // Detect collision between this entity and all the other ones
    Entity* collidedEntity = m_collisionDetector.detectAABBCollision(m_entities, entity);
    if (collidedEntity != nullptr)
    {
      // resolve collision and update both entities
      m_collisionResolver.resolveCollision(collidedEntity, entity);
      entity->update(m_window, m_deltaTime);
      collidedEntity->update(m_window, m_deltaTime);
    }
    else
    {
      entity->update(m_window, m_deltaTime);
    }
  }
  for (auto entity : m_entities)
  {
    entity->resetUpdateFlag();
  }
  */

}

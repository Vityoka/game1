#ifndef ENTITY_H_GUARD
#define ENTITY_H_GUARD

#include <SFML/Graphics.hpp>
#include <Vector>

class Entity
{
private:
    
protected:
    sf::Vector2f m_position;
    sf::Vector2f m_prevPosition;
    sf::Vector2f m_velocity = {0.0f, 0.0f};
    float m_mass = 1e10f;
public:
    Entity() {};
    Entity(float posX, float posY) : m_position{ posX, posY } { m_position.x = posX; m_position.y = posY; }
    virtual void update(sf::Window& window) = 0;
    virtual void calcNextPos(float deltaTime) = 0;
    virtual void savePrevPos() = 0;
    virtual void restorePos() = 0;
    virtual const sf::Shape& getShape(void) = 0;
    virtual const sf::Vector2f& getPosition(void) { return m_position; };
    virtual const sf::Vector2f& getVelocity(void) { return m_velocity; };
    virtual const float getMass(void) { return m_mass; };
    virtual void setVelocity(const sf::Vector2f velocity) { m_velocity = velocity; };
};

#endif //ENTITY_H_GUARD
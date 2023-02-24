#ifndef ENTITY_H_GUARD
#define ENTITY_H_GUARD

#include <SFML/Graphics.hpp>
#include <Vector>

class Entity
{
private:
    
protected:
    float m_posX = 0.0f;
    float m_posY = 0.0f;
    float m_prevPosX = 0.0f;
    float m_prevPosY = 0.0f;
public:
    Entity() {};
    Entity(float posX, float posY) { m_posX = posX; m_posY = posY; }
    virtual void update(sf::Window& window) = 0;
    virtual void calcNextPos(float deltaTime) = 0;
    virtual void savePrevPos() = 0;
    virtual void restorePos() = 0;
    virtual const sf::Shape& getShape(void) = 0;
};

#endif //ENTITY_H_GUARD
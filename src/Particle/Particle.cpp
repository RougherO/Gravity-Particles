#include "../App/App.hpp"
#include "Particle.hpp"
#include <source_location>
#include <iostream>

Particle::Particle()
{
}

Particle::Particle(float mass, float x, float y, float radius, const sf::Color& color)
    : mass { mass }
    , Coords { x, y }
    , radius { radius }
    , color { color }
    , trails { 100, sf::Vector2f { x, y }, radius, color }
{
    m_circle.setOrigin(radius, radius);
    m_circle.setPosition(Coords);
    m_circle.setFillColor(color);
}

void Particle::setPosition(const sf::Vector2f& pos)
{
    Coords = pos;
    m_circle.setPosition(pos);
}

#include "../App/App.hpp"
#include "Particle.hpp"
#include <iostream>

Particle::Particle()
{
    m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius());
}

Particle::Particle(double mass, double x, double y)
    : mass { mass }
    , X { x }
    , Y { y }
{
    m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius());
    m_circle.setPosition(x, y);
}

void Particle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_circle, states);
}

void Particle::setPosition(float x, float y)
{
    X = x;
    Y = y;
    m_circle.setPosition(x, y);
}

void Particle::setPosition(const sf::Vector2f& pos)
{
    X = pos.x;
    Y = pos.y;
    m_circle.setPosition(pos);
}

void Particle::updatePhysics(const sf::Time& frameTime, const sf::Vector2u& windowSize)
{
    Ay = gravity;
    Vy += Ay * 1 / 10.;
    Y += Vy * 1 / 10.;
    if (X < 0 || X > windowSize.x) {
        X = windowSize.x - m_circle.getRadius();
        Vx *= -1;
    }
    if (Y < 0 || Y > windowSize.y) {
        Y = windowSize.y - m_circle.getRadius();
        Vy *= -1;
    }
    m_circle.setPosition(X, Y);
}

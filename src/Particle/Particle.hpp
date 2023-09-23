#pragma once
#include <SFML/Graphics.hpp>
#include "Trail.hpp"

struct Particle {
    // Particle attributes
    float mass {};
    float radius {};
    sf::Vector2f Coords {};
    sf::Vector2f Vel {};
    sf::Vector2f Acc {};
    sf::Vector2f oldAcc {};
    sf::Color color {};
    Trail trails;

    // Constructors
    Particle();
    Particle(float mass, float x, float y, float radius, const sf::Color& colour);

    // Public member functions
    void setPosition(const sf::Vector2f& pos);

    // SFML-Circle shape object
    sf::CircleShape m_circle { radius };
};
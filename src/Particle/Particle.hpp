#pragma once
#include <SFML/Graphics.hpp>

struct Particle : sf::Drawable, public sf::Transformable {
    // Particle attributes
    double mass {};
    double X {};
    double Y {};
    double Vx {};
    double Vy {};
    double Ax {};
    double Ay {};
    const double gravity { 9.81 };

    // Constructors
    Particle();
    Particle(double mass, double x, double y);

    // Setter functions
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& pos);

    // Public member functions
    void updatePhysics(const sf::Time& frameTime, const sf::Vector2u& windowSize);

private:
    // SFML-Circle shape object
    sf::CircleShape m_circle { 5.0 };

    // Private member functions
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
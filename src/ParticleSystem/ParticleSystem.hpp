#pragma once
#include "SFML/Graphics.hpp"
#include "../Particle/Particle.hpp"

struct ParticleSystem : sf::Drawable {
    // Particle System attributes
    std::size_t m_maxParticleCount {};
    std::size_t m_particleCount {};
    bool m_maxParticleCountReached {};
    std::vector<Particle> m_particles {};

    inline static const float GravConst { 30.f };
    inline static const float error { 0.0001f };

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    // Constructor
    ParticleSystem(std::size_t particleCount);

    // Public member function
    void spawnParticle(const sf::Vector2u& mousePosition);
    void updatePositions(float updateRate);
    void solveForces();
    void updateVelocities(float updateRate);
    void solveCollisions(Particle& particle);
    void solveConstraints(const sf::Vector2u& windowSize);
    void updatePhysics(float updateRate, const sf::Vector2u& windowSize);
};
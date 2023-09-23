#include "ParticleSystem.hpp"
#include <cmath>
#include "../Utility/Randomizer.hpp"

ParticleSystem::ParticleSystem(std::size_t particleCount)
    : m_maxParticleCount { particleCount }
{
    m_particles.reserve(particleCount);
}

void ParticleSystem::updatePositions(float updateRate)
{
    for (auto& i : m_particles) {
        i.Coords += i.Vel * updateRate + 0.5f * i.Acc * updateRate * updateRate;
    }
}

void ParticleSystem::solveForces()
{
    for (auto it = m_particles.begin(); it < m_particles.end(); ++it) {
        sf::Vector2f axis {};
        it->oldAcc = it->Acc;
        it->Acc = { 0.f, 0.f };
        float dist {};
        for (auto jt = m_particles.begin(); jt < m_particles.end(); ++jt) {
            if (it != jt) {
                axis = (jt->Coords - it->Coords);
                dist = std::sqrt(axis.x * axis.x + axis.y * axis.y);
                it->Acc += ((GravConst * jt->mass) / (dist * dist + error)) * axis;
            }
        }
        // it->Acc = { 0, it->gravity };
    }
}

void ParticleSystem::updateVelocities(float updateRate)
{
    for (auto& i : m_particles) {
        i.Vel += (i.Acc + i.oldAcc) * 0.5f * updateRate;
    }
}

void ParticleSystem::solveCollisions(Particle& i)
{
}

void ParticleSystem::solveConstraints(const sf::Vector2u& windowSize)
{
    for (auto& i : m_particles) {
        if (i.Coords.x > windowSize.x - i.radius) {
            i.Coords.x = windowSize.x - i.radius - (i.Coords.x - windowSize.x + i.radius);
            i.Vel.x *= -1;
        } else if (i.Coords.x < i.radius) {
            i.Coords.x = i.radius + (i.radius - i.Coords.x);
            i.Vel.x *= -1;
        }
        if (i.Coords.y > windowSize.y - i.radius) {
            i.Coords.y = windowSize.y - i.radius - (i.Coords.y - windowSize.y + i.radius);
            i.Vel.y *= -1;
        } else if (i.Coords.y < i.radius) {
            i.Coords.y = i.radius + (i.radius - i.Coords.y);
            i.Vel.y *= -1;
        }
        i.setPosition(i.Coords);
        i.trails.push(i.Coords);
    }
}

void ParticleSystem::updatePhysics(float updateRate, const sf::Vector2u& windowSize)
{
    updatePositions(updateRate);
    solveForces();
    updateVelocities(updateRate);
    solveConstraints(windowSize);
}

void ParticleSystem::spawnParticle(const sf::Vector2u& windowSize)
{
    m_particles.clear();
    for (std::size_t i {}; i < m_maxParticleCount; ++i) {
        float red = Randomizer::Random() * 255;
        float green = Randomizer::Random() * 255;
        float blue = Randomizer::Random() * 255;
        float radius = 10.f + Randomizer::Random() * (20.f - 10.f);
        float x = radius + Randomizer::Random() * ((windowSize.x - radius) - radius);
        float y = radius + Randomizer::Random() * ((windowSize.y - radius) - radius);
        m_particles.emplace_back(radius + Randomizer::Random() * 10.f, x, y, radius, sf::Color(red, green, blue));
    }
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& i : m_particles) {
        target.draw(i.m_circle, states);
        target.draw(i.trails);
    }
}

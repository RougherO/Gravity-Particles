#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "../Utility/Randomizer.hpp"

struct Trail : sf::Drawable {
    std::size_t max_size {};
    float trailWidth {};
    sf::Vector2f lastPosition {};
    sf::Color trailColor {};
    mutable std::vector<sf::Vertex> trailCoords {};

    Trail();
    Trail(std::size_t length, const sf::Vector2f& startPos, float trailWidth, const sf::Color& trailColor);
    void push(sf::Vertex point);

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
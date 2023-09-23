#include "Trail.hpp"
#include <cmath>
#include <algorithm>

Trail::Trail()
{
}

Trail::Trail(std::size_t length, const sf::Vector2f& startPos, float width, const sf::Color& color)
    : max_size { 2 * length }
    , lastPosition { startPos }
    , trailWidth { width }
    , trailColor { color }
{
    trailCoords.reserve(max_size);
}

void Trail::push(sf::Vertex point)
{
    sf::Vector2f axis = point.position - lastPosition;
    lastPosition = point.position;
    std::swap(axis.x, axis.y);
    axis.y *= -1.f;
    float dist = std::sqrt(axis.x * axis.x + axis.y * axis.y);
    if (dist)
        axis /= dist;
    if (trailCoords.size() == max_size) {
        auto it = std::shift_left(trailCoords.begin(), trailCoords.end(), 2);
        it[0] = point.position + trailWidth * 0.5f * axis;
        it[1] = point.position - trailWidth * 0.5f * axis;
        return;
    }
    trailCoords.emplace_back(point.position + trailWidth * 0.5f * axis);
    trailCoords.emplace_back(point.position - trailWidth * 0.5f * axis);
}

void Trail::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (std::size_t cnt {}; auto& i : trailCoords) {
        i.color = trailColor;
        i.color.a = std::ceil(static_cast<float>(cnt) / trailCoords.size() * 255);
        cnt += 1;
    }
    target.draw(&trailCoords[0], trailCoords.size(), sf::TriangleStrip, states);
}

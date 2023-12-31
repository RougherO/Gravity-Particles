#pragma once
#include <SFML/Graphics.hpp>
#include "../ParticleSystem/ParticleSystem.hpp"
#include <string>
#include <memory>

class App {
    // Private members
private:
    // Application window settings
    std::size_t m_windowWidth {};
    std::size_t m_windowHeight {};
    std::string m_title {};
    std::unique_ptr<sf::RenderWindow> m_window {};

    // Event handler
    sf::Event m_eventHandler {};

    // Clock and Time handling for per frame
    sf::Clock m_clock {};
    sf::Time m_frameTime {};
    float m_updateRate { 0.02 };

    // Particle object
    ParticleSystem ps { 10 };

    // Public Constructors
public:
    // Default Constructor to create a window of width x height
    App(std::size_t width, std::size_t height, std::string title);

    // Public member functions
    void update();
    void render();
    void run();
};

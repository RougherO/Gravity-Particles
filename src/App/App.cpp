#include "App.hpp"

App::App(std::size_t width, std::size_t height, std::string title)
    : m_windowWidth { width }
    , m_windowHeight { height }
    , m_title { title }
    , m_window { std::make_unique<sf::RenderWindow>(sf::VideoMode(m_windowWidth, m_windowHeight), title, sf::Style::Default) }
{
    m_particle.setPosition(m_windowWidth / 2, m_windowHeight / 2);
    m_window->setFramerateLimit(120);
}

void App::update()
{
    while (m_window->pollEvent(m_eventHandler)) {
        switch (m_eventHandler.type) {
        case sf::Event::Closed:
            m_window->close();
            break;
        default:
            break;
        }
    }
    m_frameTime = m_clock.restart();
    m_particle.updatePhysics(m_frameTime, m_window->getSize());
}

void App::render()
{
    m_window->draw(m_particle);
    m_window->display();
    m_window->clear();
}

void App::run()
{
    while (m_window->isOpen()) {
        update();
        render();
    }
}
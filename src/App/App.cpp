#include "App.hpp"

App::App(std::size_t width, std::size_t height, std::string title)
    : m_windowWidth { width }
    , m_windowHeight { height }
    , m_title { title }
    , m_window { std::make_unique<sf::RenderWindow>(sf::VideoMode(m_windowWidth, m_windowHeight), title, sf::Style::Default) }
{
    m_window->setFramerateLimit(120);
    ps.spawnParticle(m_window->getSize());
}

void App::update()
{
    // if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    //     ps.spawnParticle(m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window)));
    // }
    while (m_window->pollEvent(m_eventHandler)) {
        switch (m_eventHandler.type) {
        case sf::Event::Closed:
            m_window->close();
            break;
        case sf::Event::MouseButtonPressed:
            ps.spawnParticle(m_window->getSize());
        default:
            break;
        }
    }
    ps.updatePhysics(m_updateRate, m_window->getSize());
    m_frameTime = m_clock.restart();
}

void App::render()
{
    m_window->draw(ps);
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
#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode({1280, 720}), "Drone Swarm Simulator") {
    window.setFramerateLimit(60);
    for (int i = 0; i < 50; i++) {
        float rx = std::rand() % 1280;
        float ry = std::rand() % 720;
        swarm.addBoid(rx, ry);
    }
}

void Engine::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Engine::processEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Engine::update() {
    swarm.updateAll();
}

void Engine::render() {
    window.clear(sf::Color::Black);
    for (const auto& boid : swarm.getBoids()) {
        sf::CircleShape shape(5.0f, 3);
        shape.setPosition({boid.getPosition().x, boid.getPosition().y});
        window.draw(shape);
    }
    window.display();
}
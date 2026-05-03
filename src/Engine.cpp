#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode({1280, 720}), "Drone Swarm Simulator") {
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    for (int i = 0; i < 50; i++) {
        float rx = std::rand() % 1280;
        float ry = std::rand() % 720;
        swarm.addBoid(rx, ry);
    }
}

Engine::~Engine() {
    ImGui::SFML::Shutdown();
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
        ImGui::SFML::ProcessEvent(window, *event);

        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Engine::update() {
    ImGui::SFML::Update(window, deltaClock.restart());
    ImGui::SetNextWindowPos(ImVec2(5, 5), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(400, 150), ImGuiCond_FirstUseEver);

    ImGui::Begin("Controls");
    ImGui::SliderFloat("Separation", &weightSep, 0.0f, 5.0f);
    ImGui::SliderFloat("Alignment", &weightAli, 0.0f, 5.0f);
    ImGui::SliderFloat("Cohesion", &weightCoh, 0.0f, 5.0f);
    ImGui::End();

    swarm.updateAll(weightSep, weightAli, weightCoh);
}

void Engine::render() {
    window.clear(sf::Color::Black);

    for (const auto& boid : swarm.getBoids()) {
        sf::CircleShape shape(5.0f, 3);
        shape.setPosition({boid.getPosition().x, boid.getPosition().y});

        Vector2D vel = boid.getVelocity();
        float angle = std::atan2(vel.y, vel.x) * 180.0f / 3.14159265f;
        shape.setRotation(sf::degrees(angle + 90.0f));

        window.draw(shape);
    }

    ImGui::SFML::Render(window);

    window.display();
}
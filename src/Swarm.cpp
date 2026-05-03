#include "Swarm.hpp"

Swarm::Swarm() {}

void Swarm::addBoid(float x, float y) {
    boids.emplace_back(x, y);
}

void Swarm::updateAll() {
    for (auto& boid : boids) {
        boid.flock(boids);
        boid.update();
        boid.edges(1280.0f, 720.0f);
    }
}

const std::vector<Boid> &Swarm::getBoids() const {
    return boids;
}
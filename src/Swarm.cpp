#include "Swarm.hpp"

Swarm::Swarm() {}

void Swarm::addBoid(float x, float y) {
    boids.emplace_back(x, y);
}

void Swarm::updateAll(float wSep, float wAli, float wCoh) {
    for (auto& boid : boids) {
        boid.flock(boids, wSep, wAli, wCoh);
        boid.update();
        boid.edges(1280.0f, 720.0f);
    }
}

const std::vector<Boid> &Swarm::getBoids() const {
    return boids;
}
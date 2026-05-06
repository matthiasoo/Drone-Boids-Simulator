#include "Swarm.hpp"

Swarm::Swarm() {}

void Swarm::addBoid(float x, float y) {
    boids.emplace_back(x, y);
}

void Swarm::updateAll(float wSep, float wAli, float wCoh, float rSep, float rAli, float rCoh) {
    for (auto& boid : boids) {
        boid.flock(boids, wSep, wAli, wCoh, rSep, rAli, rCoh);
        boid.update();
        boid.edges(1280.0f, 720.0f);
    }
}

const std::vector<Boid> &Swarm::getBoids() const {
    return boids;
}
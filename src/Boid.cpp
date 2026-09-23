#include "Boid.hpp"
#include <random>

namespace {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);
}

Boid::Boid(float x, float y) : 
    position(x, y),
    velocity(dist(gen), dist(gen)),
    acceleration(0, 0),
    maxSpeed(4.0f),
    maxForce(0.05f) {}

void Boid::applyForce(const Vector2D& force) {
    acceleration += force;
}

void Boid::update() {
    velocity += acceleration;
    velocity.limit(maxSpeed);
    position += velocity;
    acceleration *= 0;
}

void Boid::flock(const std::vector<Boid>& boids, float wSep, float wAli, float wCoh, float rSep, float rAli, float rCoh) {
    Vector2D sep = separate(boids, rSep);
    Vector2D ali = align(boids, rAli);
    Vector2D coh = cohere(boids, rCoh);

    sep *= wSep;
    ali *= wAli;
    coh *= wCoh;

    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

void Boid::edges(float width, float height) {
    if (position.x > width) position.x = 0;
    else if (position.x < 0) position.x = width;
    
    if (position.y > height) position.y = 0;
    else if (position.y < 0) position.y = height;
}

Vector2D Boid::getPosition() const {
    return position;
}

Vector2D Boid::getVelocity() const {
    return velocity;
}

Vector2D Boid::separate(const std::vector<Boid>& boids, float radius) {
    float desiredSeparation = radius;
    Vector2D steer = Vector2D(0, 0);
    int count = 0;

    for (const auto &other : boids){
        float d = position.distance(other.position);
        if (d > 0 && d < desiredSeparation) {
            Vector2D esc = position - other.position;
            esc.normalize();
            esc /= d;
            steer += esc;
            count++;
        }
    }

    if (count > 0) {
        steer /= count;
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit(maxForce);
    }

    return steer;
}

Vector2D Boid::align(const std::vector<Boid>& boids, float radius) {
    float neighborDist = radius;
    Vector2D steer = Vector2D(0, 0);
    int count = 0;

    for (const auto &other : boids){
        float d = position.distance(other.position);
        if (d > 0 && d < neighborDist) {
            steer += other.velocity;
            count++;
        }
    }

    if (count > 0) {
        steer /= count;
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit(maxForce);
    }

    return steer;
}

Vector2D Boid::cohere(const std::vector<Boid>& boids, float radius) {
    float neighborDist = radius;
    Vector2D steer = Vector2D(0, 0);
    int count = 0;

    for (const auto &other : boids){
        float d = position.distance(other.position);
        if (d > 0 && d < neighborDist) {
            steer += other.position;
            count++;
        }
    }

    if (count > 0) {
        steer /= count;
        steer -= position;
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit(maxForce);
    }

    return steer;
}
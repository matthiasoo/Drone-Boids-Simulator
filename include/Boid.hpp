#include <vector>
#include "Vector2D.hpp"

class Boid {
private:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    float maxSpeed;
    float maxForce;

    Vector2D separate(const std::vector<Boid>& boids);
    Vector2D align(const std::vector<Boid>& boids);
    Vector2D cohere(const std::vector<Boid>& boids);

public:
    Boid(float x, float y);
    void applyForce(const Vector2D& force);
    void update();
    void flock(const std::vector<Boid>& boids, float wSep, float wAli, float wCoh);
    void edges(float width, float height);
    Vector2D getPosition() const;
    Vector2D getVelocity() const;
};
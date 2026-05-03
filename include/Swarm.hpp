#include <vector>
#include "Boid.hpp"


class Swarm {
private:
    std::vector<Boid> boids;

public:
    Swarm();
    void addBoid(float x, float y);
    void updateAll();
    const std::vector<Boid>& getBoids() const;
};
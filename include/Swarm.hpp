#include <vector>
#include "Boid.hpp"


class Swarm {
private:
    std::vector<Boid> boids;

public:
    Swarm();
    void addBoid(float x, float y);
    void updateAll(float wSep, float wAli, float wCoh, float rSep, float rAli, float rCoh);
    const std::vector<Boid>& getBoids() const;
};
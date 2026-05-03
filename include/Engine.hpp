#include <SFML/Graphics.hpp>
#include "Swarm.hpp"

class Engine {
private:
    sf::RenderWindow window;
    Swarm swarm;

    void processEvents();
    void update();
    void render();

public:
    Engine();
    void run();
};
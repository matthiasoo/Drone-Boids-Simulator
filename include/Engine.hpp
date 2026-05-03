#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-sfml.h>
#include "Swarm.hpp"

class Engine {
private:
    sf::RenderWindow window;
    Swarm swarm;

    sf::Clock deltaClock;

    float weightSep = 1.5f;
    float weightAli = 1.0f;
    float weightCoh = 1.0f;

    void processEvents();
    void update();
    void render();

public:
    Engine();
    ~Engine();
    void run();
};
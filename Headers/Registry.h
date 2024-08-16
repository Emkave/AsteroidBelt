#ifndef ASTEROIDBELT_REGISTRY_H
#define ASTEROIDBELT_REGISTRY_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <atomic>
#include <stack>

using namespace sf;

namespace Registry {
    extern constinit const unsigned short WIN_HEIGHT;
    extern constinit const unsigned short WIN_LENGHT;
    extern constinit const unsigned short FPS;

    extern std::atomic<Event *> event;
    extern std::atomic<RenderWindow *> window;
}

#endif //ASTEROIDBELT_REGISTRY_H

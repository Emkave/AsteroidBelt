#ifndef ASTEROIDBELT_REGISTRY_H
#define ASTEROIDBELT_REGISTRY_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <atomic>

using namespace sf;

namespace Registry {
    extern const unsigned short WIN_HEIGHT;
    extern const unsigned short WIN_LENGHT;
    extern const unsigned short FPS;

    extern std::atomic<Event *> event;
    extern RenderWindow * window;
}

#endif //ASTEROIDBELT_REGISTRY_H

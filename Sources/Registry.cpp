#include "../Headers/Registry.h"

namespace Registry {
    constinit const unsigned short WIN_LENGHT = 1280;
    constinit const unsigned short WIN_HEIGHT = 720;
    constinit const unsigned short FPS = 100;

    std::atomic<RenderWindow *> window = nullptr;
    std::atomic<Event *> event = nullptr;
}
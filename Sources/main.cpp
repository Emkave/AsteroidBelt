#include "../Headers/Registry.h"

#include <SFML/Window/Event.hpp>
#include <vld.h>
#include <iostream>


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Registry::window = new RenderWindow(VideoMode(Registry::WIN_LENGHT, Registry::WIN_HEIGHT), "Asteroid Belt", Style::Titlebar | Style::Close);
    Registry::event.store(new Event(), std::memory_order_release);
    Registry::window->setFramerateLimit(Registry::FPS);

    while (Registry::window->isOpen()) {

        Event * event_ptr = Registry::event.load(std::memory_order_acquire);
        while (Registry::window->pollEvent(*event_ptr)) {
            if (event_ptr->type == Event::Closed) {
                Registry::window->close();
            }
        }

        Registry::window->clear();

        Registry::window->display();
    }


    end:
    delete Registry::window;
    delete Registry::event.load(std::memory_order_acquire);

    return 0;
}

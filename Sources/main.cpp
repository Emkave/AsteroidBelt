#include "../Headers/Registry.h"

#include <SFML/Window/Event.hpp>
#include <vld.h>
#include <iostream>


int main(void) {
    Registry::window = new RenderWindow(VideoMode(Registry::WIN_LENGHT, Registry::WIN_HEIGHT), "Asteroid Belt", Style::Titlebar | Style::Close);
    Registry::window->setFramerateLimit(Registry::FPS);

    while (Registry::window->isOpen()) {
        Event event {};

        while (Registry::window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                Registry::window->close();
            }
        }

        Registry::window->clear();

        Registry::window->display();
    }


    end:
    delete Registry::window;

    return 0;
}

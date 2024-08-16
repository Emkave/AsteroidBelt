#include "../Headers/Registry.h"

#include <SFML/Window/Event.hpp>
#include <vld.h>
#include <iostream>
#include <stack>
#include "../Headers/Scene/Scene.h"
#include "../Headers/Scene/MakeScene.h"

std::stack<std::unique_ptr<Scene>> scene_stack;


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Registry::window.store(new RenderWindow(VideoMode(Registry::WIN_LENGHT, Registry::WIN_HEIGHT), "Asteroid Belt", Style::None | Style::Close), std::memory_order_release);
    Registry::event.store(new Event(), std::memory_order_release);
    Registry::window.load(std::memory_order_acquire)->setFramerateLimit(Registry::FPS);

    scene_stack.emplace(MakeScene::MainMenu());

    while (Registry::window.load(std::memory_order_acquire)->isOpen()) {
        RenderWindow * window_ptr = Registry::window.load(std::memory_order_acquire);
        Event * event_ptr = Registry::event.load(std::memory_order_acquire);

        while (window_ptr->pollEvent(*event_ptr)) {
            if (event_ptr->type == Event::Closed) {
                window_ptr->close();
            }
        }

        window_ptr->clear(Color::Black);
        scene_stack.top()->render();
        window_ptr->display();
    }


    end:
    delete Registry::window.load(std::memory_order_acquire);
    delete Registry::event.load(std::memory_order_acquire);

    for (size_t i=0; i<scene_stack.size(); i++) {
        scene_stack.pop();
    }

    return 0;
}

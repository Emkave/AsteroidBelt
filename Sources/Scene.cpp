#include "../Headers/Scene/Scene.h"

void Scene::render() {
    for (std::unique_ptr<UIButton> & button : this->buttons) {
        button->draw();
    }
}
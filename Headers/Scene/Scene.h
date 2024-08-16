#ifndef ASTEROIDBELT_SCENE_H
#define ASTEROIDBELT_SCENE_H
#include "../UI/Button/UIButton.h"

#include <list>


class Scene {
private:
    std::unique_ptr<Texture> background_image = nullptr;
    std::unique_ptr<Sprite> sprite = nullptr;

    std::list<std::unique_ptr<UIButton>> buttons;


public:
    inline void render(void);
    void set_background_image(const std::string & img_path);
    void emplace_button(std::unique_ptr<UIButton> & button);
};


inline void Scene::render() {
    Registry::window.load(std::memory_order_acquire)->draw(*this->sprite);

    for (std::unique_ptr<UIButton> & button : this->buttons) {
        button->draw();
    }
}





#endif //ASTEROIDBELT_SCENE_H

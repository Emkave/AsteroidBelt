#include "../Headers/Scene/Scene.h"

void Scene::set_background_image(const std::string & img_path) {
    this->background_image = std::make_unique<Texture>();

    if (!this->background_image->loadFromFile(img_path)) {
        throw std::runtime_error("Scene::set_background_image() -> Invalid or the path does not exist.");
    }

    this->sprite = std::make_unique<Sprite>();

    this->sprite->setTexture(*this->background_image);
    const Vector2u texture_size = this->background_image->getSize();
    const Vector2u window_size = Registry::window.load(std::memory_order_acquire)->getSize();
    const float scale_x = static_cast<float>(window_size.x) / static_cast<float>(texture_size.x);
    const float scale_y = static_cast<float>(window_size.y) / static_cast<float>(texture_size.y);
    this->sprite->setScale(scale_x, scale_y);
}


void Scene::emplace_button(std::unique_ptr<UIButton> & button) {
    this->buttons.emplace_back(std::move(button));
}

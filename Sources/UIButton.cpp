#include "../Headers/UI/Button/UIButton.h"


void UIButton::attach_sound(const std::string & sound_path) {
    if (!UIButton::sound_buffer) {
        UIButton::sound_buffer = std::make_unique<SoundBuffer>();
    }

    if (!UIButton::sound_buffer->loadFromFile(sound_path)) {
        throw std::runtime_error("UIButton::attach_sound() -> Invalid or the path does not exist.");
    }

    if (!UIButton::sound) {
        UIButton::sound = std::make_unique<Sound>();
    }

    UIButton::sound->setBuffer(*UIButton::sound_buffer);
}


void UIButton::execute(void) {
    if (this->action) {
        this->action();
    }
}


void UIButton::attach_action(void (*f)(void)) {
    this->action = f;
}
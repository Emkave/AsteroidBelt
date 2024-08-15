#ifndef ASTEROIDBELT_UIBUTTON_H
#define ASTEROIDBELT_UIBUTTON_H
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "../../Registry.h"
#include <memory>


using namespace sf;

class UIButton {
protected:
    static std::unique_ptr<Sound> sound;
    static std::unique_ptr<SoundBuffer> sound_buffer;

    std::unique_ptr<Shape> shape = nullptr;

    inline bool is_mouse_over_shape(void);

    bool is_pressed = false;
    bool is_hovered = false;
    void (*action)(void);

public:
    virtual void press(void) = 0;
    virtual void hover(void) = 0;
    virtual void release(void) = 0;
    virtual void set_position(Vector2f position);
    virtual void set_size(Vector2f size);

    static void attach_sound(const std::string & sound_path);

    void attach_action(void (*f)(void));
    void execute(void);
};

std::unique_ptr<SoundBuffer> UIButton::sound_buffer = nullptr;
std::unique_ptr<Sound> UIButton::sound = nullptr;


inline bool UIButton::is_mouse_over_shape(void) {
    const Vector2i mouse_pos = Mouse::getPosition(*Registry::window);
    return this->shape->getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));
}


#endif //ASTEROIDBELT_UIBUTTON_H

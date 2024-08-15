#ifndef ASTEROIDBELT_UIBUTTON_H
#define ASTEROIDBELT_UIBUTTON_H
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Color.hpp>
#include "../../Registry.h"
#include <memory>

using namespace sf;

class UIButton {
protected:
    static std::unique_ptr<Sound> sound;
    static std::unique_ptr<SoundBuffer> sound_buffer;

    std::unique_ptr<Shape> shape = nullptr;
    std::unique_ptr<Color> base_color = nullptr;
    std::unique_ptr<Color> hover_color = nullptr;
    std::unique_ptr<Color> press_color = nullptr;

    inline bool is_mouse_over_shape(void);
    inline unsigned short __get_state(void);

    bool is_pressed = false;
    bool is_hovered = false;
    void (*action)(void);

public:
    virtual void set_position(Vector2f position) = 0;
    virtual void set_size(Vector2f size) = 0;
    virtual void set_size(unsigned short radius) = 0;
    virtual inline void draw(void) = 0;

    static void attach_sound(const std::string & sound_path);
    void attach_action(void (*f)(void));
    void execute(void);
    void set_base_color(Color color);
    void set_hover_color(Color color);
    void set_press_color(Color color);
};


inline bool UIButton::is_mouse_over_shape(void) {
    const Vector2i mouse_pos = Mouse::getPosition(*Registry::window);
    return this->shape->getGlobalBounds().contains(static_cast<float>(mouse_pos.x), static_cast<float>(mouse_pos.y));
}


inline unsigned short UIButton::__get_state(void) {
    unsigned short state = 0;

    if (this->is_mouse_over_shape()) {
        state |= 1;

        Event * event_ptr = Registry::event.load(std::memory_order_acquire);
        if (event_ptr->type == Event::MouseButtonPressed) {
            if (event_ptr->mouseButton.button == Mouse::Left) {
                state |= 2;
            }
        }
    }

    return state;
}

#endif //ASTEROIDBELT_UIBUTTON_H

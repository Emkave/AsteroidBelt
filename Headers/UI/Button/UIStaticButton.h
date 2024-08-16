
#ifndef ASTEROIDBELT_UISTATICBUTTON_H
#define ASTEROIDBELT_UISTATICBUTTON_H
#include <SFML/Graphics/Text.hpp>
#include "UIButton.h"

class UIStaticButton : public UIButton {
private:
    Text text;

    static std::unique_ptr<Font> font;

public:
    explicit UIStaticButton(const char c) : UIButton(c) {}

    void set_position(Vector2f position) override;
    void set_size(Vector2f size) override;
    void set_size(unsigned short radius) override;
    void set_font(const std::string & font_path);
    void set_string(const std::string & string);
    void set_string_color(Color color);
    void set_string_outline_color(Color color);
    void set_font_size(unsigned short size);
    void center_text(void);
    inline void draw(void) override;

};


void UIStaticButton::center_text() {
    if (!this->shape) {
        return;
    }

    FloatRect text_rect = this->text.getLocalBounds();
    this->text.setOrigin(text_rect.left + text_rect.width/2.0f, text_rect.top + text_rect.height/2.0f);
    FloatRect shape_bounds = this->shape->getGlobalBounds();
    this->text.setPosition(shape_bounds.left + shape_bounds.width/2.0f, shape_bounds.top + shape_bounds.height/2.0f);
}


inline void UIStaticButton::draw(void) {
    switch (this->__get_state()) {
        case 0: {
            if (this->base_color) {
                this->shape->setFillColor(*this->base_color);
            }
        }
            break;

        case 1: {
            if (this->hover_color) {
                this->shape->setFillColor(*this->hover_color);
            }
        }
            break;

        case 3: {
            if (this->press_color) {
                this->shape->setFillColor(*this->press_color);
                this->execute();
            }
        }
            break;

        default:
            break;
    }

    RenderWindow * window_ptr = Registry::window.load(std::memory_order_acquire);

    window_ptr->draw(*this->shape);
    window_ptr->draw(this->text);
}

#endif //ASTEROIDBELT_UISTATICBUTTON_H

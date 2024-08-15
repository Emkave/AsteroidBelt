
#ifndef ASTEROIDBELT_UISTATICBUTTON_H
#define ASTEROIDBELT_UISTATICBUTTON_H
#include <SFML/Graphics/Text.hpp>
#include "UIButton.h"

class UIStaticButton : public UIButton {
private:
    Text text;

    void __center_text(void);

public:
    void set_position(Vector2f position) override;
    void set_size(Vector2f size) override;
    void set_size(unsigned short radius) override;
    inline void draw(void) override;

    Text & self(void);
};


void UIStaticButton::__center_text(void) {
    if (!this->shape) {
        return;
    }

    FloatRect text_rect = this->text.getGlobalBounds();
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
}



#endif //ASTEROIDBELT_UISTATICBUTTON_H

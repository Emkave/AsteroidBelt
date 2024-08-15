#include "../Headers/UI/Button/UIStaticButton.h"

Text & UIStaticButton::self(void) {
    return this->text;
}


void UIStaticButton::set_size(Vector2f size) {
    if (!this->shape) {
        throw std::runtime_error("UIStaticButton::set_size() -> Nothing to set size to.");
    }

    if (typeid(*this->shape) != typeid(RectangleShape)) {
        throw std::runtime_error("UIStaticButton::set_size() -> Setting the size to rectangular shape failed.");
    }

    RectangleShape * shape_ptr = dynamic_cast<RectangleShape*>(this->shape.get());

    if (!shape_ptr) {
        throw std::runtime_error("UIStaticButton::set_size() -> The shape is not a RectangleShape.");
    }

    shape_ptr->setSize(size);
}


void UIStaticButton::set_size(unsigned short radius) {
    if (!this->shape) {
        throw std::runtime_error("UIStaticButton::set_size() -> Nothing to set size to.");
    }

    if (typeid(*this->shape) != typeid(CircleShape)) {
        throw std::runtime_error("UIStaticButton::set_size() -> Setting the size to circular shape failed.");
    }

    CircleShape * shape_ptr = dynamic_cast<CircleShape*>(this->shape.get());

    if (!shape_ptr) {
        throw std::runtime_error("UIStaticButton::set_size() -> The shape is not a CircleShape.");
    }

    shape_ptr->setRadius(radius);
}



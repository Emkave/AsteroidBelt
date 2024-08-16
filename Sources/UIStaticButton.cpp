#include "../Headers/UI/Button/UIStaticButton.h"

std::unique_ptr<Font> UIStaticButton::font = nullptr;


void UIStaticButton::set_size(Vector2f size) {
    if (!this->shape) {
        throw std::runtime_error("UIStaticButton::set_size() -> Nothing to set size to.");
    }

    if (RectangleShape * shape_ptr = dynamic_cast<RectangleShape*>(this->shape.get())) {
        shape_ptr->setSize(size);
    } else {
        throw std::runtime_error("UIStaticButton::set_size() -> Setting the size to rectangular shape failed.");
    }
}


void UIStaticButton::set_size(unsigned short radius) {
    if (!this->shape) {
        throw std::runtime_error("UIStaticButton::set_size() -> Nothing to set size to.");
    }

    if (CircleShape * shape_ptr = dynamic_cast<CircleShape*>(this->shape.get())) {
        shape_ptr->setRadius(radius);
    } else {
        throw std::runtime_error("UIStaticButton::set_size() -> Setting the size to circular shape failed.");
    }
}


void UIStaticButton::set_position(Vector2f position) {
    if (!this->shape) {
        throw std::runtime_error("UIStaticButton::set_position() -> Nothing to set position to.");
    }

    this->shape->setPosition(position);
}


void UIStaticButton::set_font(const std::string & font_path) {
    UIStaticButton::font = std::make_unique<Font>();

    if (!UIStaticButton::font->loadFromFile(font_path)) {
        throw std::runtime_error("UIStaticButton::set_font() -> Invalid or the path does not exist.");
    }

    this->text.setFont(*UIStaticButton::font);
}


void UIStaticButton::set_string(const std::string & string) {
    this->text.setString(string);
}


void UIStaticButton::set_string_color(Color color) {
    this->text.setFillColor(color);
}


void UIStaticButton::set_string_outline_color(Color color) {
    this->text.setOutlineColor(color);
}


void UIStaticButton::set_font_size(unsigned short size) {
    this->text.setCharacterSize(size);
}
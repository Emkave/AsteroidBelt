#include "../Headers/Scene/MakeScene.h"
#include "../Headers/UI/Button/UIStaticButton.h"

std::unique_ptr<Scene> MakeScene::MainMenu(void) {
    std::unique_ptr<Scene> main_menu = std::make_unique<Scene>();
    main_menu->set_background_image("../../Assets/Images/menubackgr.jpg");

    std::unique_ptr<UIButton> start = std::make_unique<UIStaticButton>('c');
    start->set_base_color({250, 250, 250, 180});
    start->set_hover_color({200, 200, 200, 180});
    start->set_press_color({100, 100, 100, 180});
    start->set_size({300, 60});
    start->set_position({static_cast<float>(Registry::window.load(std::memory_order_acquire)->getSize().x / 2.0) - std::visit([](auto && size) -> float {
        using T = std::decay_t<decltype(size)>;
        if constexpr (std::is_same_v<T, float>) {
            return size;
        } else if constexpr (std::is_same_v<T, Vector2f>) {
            return size.x / 2;
        }
    }, start->get_size()) / 2, 300});
    dynamic_cast<UIStaticButton*>(start.get())->set_string("PLAY");
    dynamic_cast<UIStaticButton*>(start.get())->set_font("../../Assets/Fonts/ariblk.ttf");
    dynamic_cast<UIStaticButton*>(start.get())->set_string_color(Color::White);
    dynamic_cast<UIStaticButton*>(start.get())->set_font_size(30);
    main_menu->emplace_button(start);

    return main_menu;
}
#ifndef ASTEROIDBELT_UIDYNAMICBUTTON_H
#define ASTEROIDBELT_UIDYNAMICBUTTON_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Image.hpp>
#include "UIButton.h"

class UIDynamicButton : public UIButton {
private:
    std::unique_ptr<Texture> texture;


public:


};

#endif //ASTEROIDBELT_UIDYNAMICBUTTON_H

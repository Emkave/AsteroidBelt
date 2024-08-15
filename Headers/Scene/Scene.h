#ifndef ASTEROIDBELT_SCENE_H
#define ASTEROIDBELT_SCENE_H
#include "../UI/Button/UIButton.h"

#include <list>


class Scene {
private:
    std::list<UIButton> buttons;


public:
    void load(void);
};



#endif //ASTEROIDBELT_SCENE_H

#ifndef ASTEROIDBELT_SCENE_H
#define ASTEROIDBELT_SCENE_H
#include "../UI/Button/UIButton.h"

#include <list>


class Scene {
private:
    std::list<std::unique_ptr<UIButton>> buttons;


public:
    void render(void);
};



#endif //ASTEROIDBELT_SCENE_H

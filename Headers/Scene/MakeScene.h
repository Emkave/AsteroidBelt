#ifndef ASTEROIDBELT_MAKESCENE_H
#define ASTEROIDBELT_MAKESCENE_H
#include "Scene.h"
#include <memory>

class MakeScene {
private:

public:
    static std::unique_ptr<Scene> MainMenu(void);
    static std::unique_ptr<Scene> Options(void);
};



#endif //ASTEROIDBELT_MAKESCENE_H

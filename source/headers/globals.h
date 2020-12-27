//
// Created by Deepak Ramalingam on 12/16/20.
//

#ifndef MZPLUSPLUS_GLOBALS_H
#define MZPLUSPLUS_GLOBALS_H

namespace globals {
    const bool FULLSCREEN = false;

    const float SCREEN_SCALE = 0.5f;

    const int SCREEN_WIDTH = 1920*SCREEN_SCALE;
    const int SCREEN_HEIGHT = 1080*SCREEN_SCALE;

    const float SPRITE_SCALE = 3.5f;
}

struct Vector2 {
    int x, y;
    Vector2():
        x(0), y(0)
    {}
    Vector2(int x, int y):
        x(x), y(y)
    {}
    Vector2 zero() {
        return Vector2(0, 0);
    }
};

#endif //MZPLUSPLUS_GLOBALS_H

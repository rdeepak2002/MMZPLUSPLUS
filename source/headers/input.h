//
// Created by Deepak Ramalingam on 12/6/20.
//

#include <SDL.h>
#include <map>

#ifndef MZPLUSPLUS_INPUT_H
#define MZPLUSPLUS_INPUT_H

class Input {
public:
    void beginNewFrame();
    void keyUpEvent(const SDL_Event &event);
    void keyDownEvent(const SDL_Event& event);

    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
private:
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif //MZPLUSPLUS_INPUT_H

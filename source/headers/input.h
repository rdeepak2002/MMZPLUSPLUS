//
// Created by Deepak Ramalingam on 12/6/20.
//

#include <SDL.h>
#include <map>

#ifndef MZPLUSPLUS_INPUT_H
#define MZPLUSPLUS_INPUT_H

/*
 * Input class
 * Keeps track of keyboard state
 */

class Input {
public:
    /**
     * This function gets called at the beginning of each new frame to reset the keys that are no longer relevant.
     */
    void beginNewFrame();

    /**
     * This function gets called when a key is released.
     * @param event the SDL event that occurred
     */
    void keyUpEvent(const SDL_Event &event);

    /**
     * This function gets called when a key has been pressed.
     * @param event the SDL event that occurred
     */
    void keyDownEvent(const SDL_Event& event);

    /**
     * This function checks if a certain key was pressed during the current frame.
     * @param key the key to check if pressed
     * @return true if the key was pressed
     */
    bool wasKeyPressed(SDL_Scancode key);

    /**
     * This function checks if a certain key was released during the current frame.
     * @param key the key to check if released
     * @return true if the key was released
     */
    bool wasKeyReleased(SDL_Scancode key);

    /**
     * This function checks if a certain key is being held during the current frame.
     * @param key the key to check if it is currently being held
     * @return true if the key is currently being held
     */
    bool isKeyHeld(SDL_Scancode key);
private:
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif //MZPLUSPLUS_INPUT_H

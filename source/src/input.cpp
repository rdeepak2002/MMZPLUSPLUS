//
// Created by Deepak Ramalingam on 12/6/20.
//

#include "../headers/input.h"

/*
 * Input class
 * Keeps track of keyboard state
 */

/**
 * This function gets called at the beginning of each new frame to reset the keys that are no longer relevant.
 */
void Input::beginNewFrame() {
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
}

/**
 * This function gets called when a key has been pressed.
 * @param event the SDL event that occurred
 */
void Input::keyDownEvent(const SDL_Event &event) {
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;
}

/**
 * This function gets called when a key is released.
 * @param event the SDL event that occurred
 */
void Input::keyUpEvent(const SDL_Event &event) {
    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = false;
}

/**
 * This function checks if a certain key was pressed during the current frame.
 * @param key the key to check if pressed
 * @return true if the key was pressed
 */
bool Input::wasKeyPressed(SDL_Scancode key) {
    return this->_pressedKeys[key];
}

/**
 * This function checks if a certain key was released during the current frame.
 * @param key the key to check if released
 * @return true if the key was released
 */
bool Input::wasKeyReleased(SDL_Scancode key) {
    return this->_releasedKeys[key];
}

/**
 * This function checks if a certain key is being held during the current frame.
 * @param key the key to check if it is currently being held
 * @return true if the key is currently being held
 */
bool Input::isKeyHeld(SDL_Scancode key) {
    return this->_heldKeys[key];
}
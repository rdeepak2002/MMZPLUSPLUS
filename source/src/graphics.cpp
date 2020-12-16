//
// Created by Deepak Ramalingam on 12/6/20.
//

#include "SDL.h"

#include "../headers/graphics.h"

/*
 * Graphics class
 * Holds all information dealing with graphics
 */

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(256, 192, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "MMZ++");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
}
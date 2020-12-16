//
// Created by Deepak Ramalingam on 12/6/20.
//

#include <SDL.h>
#include <SDL_image.h>

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

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
    if(this->_spriteSheets.count(filePath) == 0) {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopy(this->_renderer, source, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->_renderer;
}
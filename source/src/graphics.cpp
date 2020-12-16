//
// Created by Deepak Ramalingam on 12/6/20.
//

#include <SDL.h>
#include <SDL_image.h>

#include "../headers/graphics.h"
#include "../headers/globals.h"

/*
 * Graphics class
 * Holds all information dealing with graphics
 */

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "MMZ++");
    SDL_ShowCursor(0);
    if(globals::FULLSCREEN) {
        toggleFullScreenMode();
    }
    else {
        toggleWindowedMode();
    }
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

void Graphics::toggleWindowedMode() {
    SDL_SetWindowFullscreen(this->_window, 0);
    SDL_SetWindowSize(this->_window, globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT);
}

void Graphics::toggleFullScreenMode() {
    SDL_SetWindowFullscreen(this->_window, 1);
}
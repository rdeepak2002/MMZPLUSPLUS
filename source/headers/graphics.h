//
// Created by Deepak Ramalingam on 12/6/20.
//

#ifndef MZPLUSPLUS_GRAPHICS_H
#define MZPLUSPLUS_GRAPHICS_H

/*
 * Graphics class
 * Holds all information dealing with graphics
 */

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    /**
     * This constructor creates the SDL window.
     */
    Graphics();

    /**
     * This deconstructor destroys thte SDL window.
     */
    ~Graphics();
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
};

#endif //MZPLUSPLUS_GRAPHICS_H

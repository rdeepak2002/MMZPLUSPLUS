//
// Created by Deepak Ramalingam on 12/6/20.
//

#ifndef MZPLUSPLUS_GRAPHICS_H
#define MZPLUSPLUS_GRAPHICS_H

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
};

#endif //MZPLUSPLUS_GRAPHICS_H

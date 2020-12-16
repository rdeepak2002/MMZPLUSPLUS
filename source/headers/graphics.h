//
// Created by Deepak Ramalingam on 12/6/20.
//

#ifndef MZPLUSPLUS_GRAPHICS_H
#define MZPLUSPLUS_GRAPHICS_H

/*
 * Graphics class
 * Holds all information dealing with graphics
 */

#include <SDL.h>
#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    /**
     * Graphics
     *
     * This constructor creates the SDL window.
     */
    Graphics();

    /**
     * ~Graphics
     *
     * This deconstructor destroys thte SDL window.
     */
    ~Graphics();

    /**
     * loadImage
     *
     * This function loads an image into the _spriteSheet's map if it doesn't already exist.
     * As a result, each image will only be loaded once.
     *
     * @param filePath the filePath of the image
     * @return the image of from the map regardless of whether or not it was just loaded
     */
    SDL_Surface* loadImage(const std::string &filePath);

    /**
     * blitSurface
     *
     * This function draws images (SDL_Textures) to the screen.
     *
     * @param source the source texture to draw
     * @param sourceRectangle the part of the texture to draw
     * @param destinationRect the area and location to draw the texture to
     */
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    /**
     *  flip
     *
     *  This function renders everything to the screen.
     */
    void flip();

    /**
     * clear
     *
     * This function clears the screen.
     */
    void clear();

    /**
     * getRenderer
     *
     * This function returns the renderer
     *
     * @return the renderer
     */
    SDL_Renderer* getRenderer() const;
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif //MZPLUSPLUS_GRAPHICS_H

//
// Created by Deepak Ramalingam on 12/16/20.
//

#ifndef MZPLUSPLUS_SPRITE_H
#define MZPLUSPLUS_SPRITE_H

#include <SDL.h>
#include <string>

class Graphics;

/**
 * Sprite class
 *
 * Holds all information for individual sprites.
 */

class Sprite {
public:
    /**
     * Sprite
     *
     * This default constructor initializes the sprite.
     */
    Sprite();

    /**
     * Sprite
     *
     * This constructor creates a sprite with set variables.
     *
     * @param graphics the graphics manager
     * @param filePath the filepath of the sprite image
     * @param sourceX the x location of the image in the sheet
     * @param sourceY the y location of the image in the sheet
     * @param width the width of the sprite image
     * @param height the height of the sprite image
     * @param posX the x position for the sprite to be placed on
     * @param posY the y position for the sprite to be placed on
     */
    Sprite(Graphics &graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
           float posX, float posY);

    /**
     * ~Sprite
     *
     * Virtual deconstructor for the sprite.
     */
    virtual ~Sprite();

    /**
     * update
     *
     * The update method for the sprite.
     */
    virtual void update();

    /**
     * draw
     *
     * @param graphics the graphics manager
     * @param x the x position to draw the sprite at
     * @param y the y position to draw the sprite at
     */
    void draw(Graphics &graphics, int x, int y);

private:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;

    float _x, _y;
};

#endif //MZPLUSPLUS_SPRITE_H

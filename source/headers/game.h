//
// Created by Deepak Ramalingam on 12/6/20.
//

#ifndef MZPLUSPLUS_GAME_H
#define MZPLUSPLUS_GAME_H

/*
 * Game class
 * This class holds all our information for our main game loop
 */

class Graphics;

class Game {
public:
    /**
     * This constructor initializes SDL and calls the initial gameLoop call.
     */
    Game();

    /**
     * This deconstructor does nothing.
     */
    ~Game();
private:
    /**
     * This function contains the gameLoop logic (events that repeat).
     */
    void gameLoop();

    /**
     * This function manages drawing graphics.
     * @param graphics the graphics object that allows for drawing
     */
    void draw(Graphics &graphics);

    /**
     * This function is called every frame.
     * @param elapsedTime the time that elapsed since the last frame
     */
    void update(float elapsedTime);
};

#endif //MZPLUSPLUS_GAME_H
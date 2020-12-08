//
// Created by Deepak Ramalingam on 12/6/20.
//

#ifndef MZPLUSPLUS_GAME_H
#define MZPLUSPLUS_GAME_H

class Graphics;

class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);
};

#endif //MZPLUSPLUS_GAME_H
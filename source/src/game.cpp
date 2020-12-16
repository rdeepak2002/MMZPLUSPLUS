//
// Created by Deepak Ramalingam on 12/6/20.
//

#include <SDL.h>

#include "../headers/game.h"
#include "../headers/graphics.h"
#include "../headers/input.h"

/*
 * Game class
 * This class holds all our information for our main game loop
 */

namespace {
    const int FPS = 60;
    const int MAX_FRAME_TIME = 1000/FPS;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    int LAST_UPDATE_TIME = SDL_GetTicks();

    // start the game loop
    while(true) {
        input.beginNewFrame();

        if(SDL_PollEvent(&event)) {
            if(event.type == SDL_KEYDOWN) {
                if(event.key.repeat == 0) {
                    input.keyDownEvent(event);
                }
            }
            else if(event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
            if(event.type == SDL_QUIT) {
                return;
            }
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;
    }
}

void Game::draw(Graphics &graphics) {

}

void Game::update(float elapsedTime) {

}
//
// Created by etber on 11/26/2018.
//

#ifndef ENEMY_SHELLCREEPER_2_S_MOVEMENT_H
#define ENEMY_SHELLCREEPER_2_S_MOVEMENT_H

#include <SDL2/SDL.h>
#include "Sprite.hpp"
#include "SDL_Plotter.h"

class s_movement {
    private:
    Sprite sprite;
    int xPos, yPos;
public:
    s_movement(ifstream &fin);

    bool setSprite(ifstream &fin, string name);

    void moveRight();
    void moveLeft();
    void moveDown();
    void fall();
    void flipped(ifstream &fin);

    Sprite getSprite() const;
    int getXPos() const;
    int getYPos() const;

};


#endif //ENEMY_SHELLCREEPER_2_S_MOVEMENT_H

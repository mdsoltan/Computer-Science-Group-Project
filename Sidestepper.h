//
// Created by etber on 12/2/2018.
//

#ifndef SHELLCREEPER_MAYBE_WORKING_SIDESTEPPER_H
#define SHELLCREEPER_MAYBE_WORKING_SIDESTEPPER_H

#include <SDL2/SDL.h>
#include "Sprite.hpp"
#include "SDL_Plotter.h"

class Sidestepper {
private:
    Sprite sprite;
    int xPos, yPos;
public:
    Sidestepper(ifstream &fin);

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


#endif //SHELLCREEPER_MAYBE_WORKING_SIDESTEPPER_H

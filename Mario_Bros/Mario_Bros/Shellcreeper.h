//
// Created by etber on 11/26/2018.
//

#ifndef ENEMY_SHELLCREEPER_2_S_MOVEMENT_H
#define ENEMY_SHELLCREEPER_2_S_MOVEMENT_H

#include <SDL2/SDL.h>
#include "Sprite.hpp"
#include "SDL_Plotter.h"
#include "CollisionBox.hpp"
#include "Wall.hpp"

class s_movement {
    private:
    Sprite sprite;
    CollisionBox collider;
    bool moveRight = true, moveLeft = false;
    double yVelocity, gravity;
    int xPos, yPos;
public:
    s_movement(ifstream &fin);

    bool setSprite(ifstream &fin, string name);

    void moveX();
    void moveDown();
    void fall();
    void flipped(ifstream &fin);
    void checkCollisionX(Wall b);
    void checkCollisionY(Wall b);
    void draw(SDL_Plotter &plotter);
    void inPipe(Wall b);

    Sprite getSprite() const;
    int getXPos() const;
    int getYPos() const;

};


#endif //ENEMY_SHELLCREEPER_2_S_MOVEMENT_H

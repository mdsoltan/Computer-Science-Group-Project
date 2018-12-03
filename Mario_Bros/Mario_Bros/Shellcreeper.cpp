//
// Created by etber on 11/26/2018.
//

#include "Shellcreeper.h"
#include <iostream>

using namespace std;

s_movement::s_movement(ifstream &fin) {
    xPos = 100;
    yPos = 100;
    gravity = 0.2;
    yVelocity = 0;
}

bool s_movement:: setSprite(ifstream &fin, string name) {
    bool success = sprite.loadFrame(fin, name.c_str());
    collider.setup(xPos, yPos, sprite.getCol(), sprite.getRow(), 'E');
    return success;
}

void s_movement::moveX() {
    if(moveRight) {
        if(xPos >= 1000) {
            xPos = 0;
        } else {
            xPos += 1;
        }
        collider.update(xPos, yPos);
        sprite.setFacingRight(true);
    } else if(moveLeft) {
        if(xPos <= 0) {
            xPos = 1000;
        } else {
            xPos -= 1;
        }
        collider.update(xPos, yPos);
        sprite.setFacingRight(false);
    }
}

void s_movement::moveDown(){
    if(yVelocity > -3) {
        yVelocity -= gravity;
    }
    
    yPos += -yVelocity;
    collider.update(xPos, yPos);
    
    if(yPos < 0) {
        yPos = 0;
    }
}

void s_movement::fall(){
    yPos+= 3;
}

Sprite s_movement::getSprite() const {
    return sprite;
}

int s_movement::getXPos() const {
    return xPos;
}

int s_movement::getYPos() const {
    return yPos;
}

void s_movement::flipped(ifstream &fin){
   sprite.loadFrame(fin, "Shellcreeper_Flipped.txt");
}



void s_movement::checkCollisionX(Wall b) {
    if(collider.checkCollision(b.getCollider())) {
        if(sprite.getFacingRight()) {
            xPos += 10;
            collider.update(xPos, yPos);
        } else {
            xPos -= 10;
            collider.update(xPos, yPos);
        }
    }
}

void s_movement::checkCollisionY(Wall b) {
    if(collider.checkCollision(b.getCollider())) {
        yPos -= -yVelocity;
        yVelocity = -1;
        collider.update(xPos, yPos);
    }
}

void s_movement::draw(SDL_Plotter &plotter) {
    sprite.draw(plotter, xPos, yPos);
}

void s_movement::inPipe(Wall b) {
    if(collider.checkCollision(b.getCollider())) {
        if(sprite.getFacingRight()) {
            xPos = 800;
            yPos = 100;
            collider.update(xPos, yPos);
            moveLeft = true;
            moveRight = false;
        } else {
            xPos = 100;
            yPos = 100;
            collider.update(xPos, yPos);
            moveRight = true;
            moveLeft = false;
        }
    }
}

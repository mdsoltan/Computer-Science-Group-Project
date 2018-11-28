//
// Created by etber on 11/26/2018.
//

#include "Shellcreeper.h"
#include <iostream>

using namespace std;

s_movement::s_movement(ifstream &fin) {
    sprite = Sprite(fin, "Shellcreeper.txt");
    xPos = 500;
    yPos = 500;
}

bool s_movement::setSprite(ifstream &fin, string name) {
    return sprite.loadFrame(fin, name.c_str());
}

void s_movement::moveRight() {
    xPos += 5;
}

void s_movement::moveLeft() {
    xPos -= 5;
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

void s_movement.flipped(ifstream &fin){
    sprite.loadFrame(fin, "ShellcreeperFlipped.txt")
}




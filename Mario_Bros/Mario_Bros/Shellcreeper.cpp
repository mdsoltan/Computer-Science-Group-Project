//
// Created by etber on 11/26/2018.
//

#include "Shellcreeper.h"
#include <iostream>

using namespace std;

s_movement::s_movement(ifstream &fin) {
    sprite = Sprite(fin, "Shellcreeper_Idle.txt");
    xPos = 500;
    yPos = 500;
}

bool s_movement:: setSprite(ifstream &fin, string name) {
    return sprite.loadFrame(fin, name.c_str());
}

void s_movement::moveRight() {
    xPos += 2;
}

void s_movement::moveLeft() {
    xPos -= 2;
}

void s_movement::moveDown(){
    if(yPos < 700){
        yPos += 3;
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
   sprite = Sprite(fin, "Shellcreeper_Flipped.txt");
}




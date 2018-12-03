//
// Created by etber on 12/2/2018.
//

#include "Sidestepper.h"
#include <iostream>

using namespace std;

Sidestepper::Sidestepper(ifstream &fin) {
    sprite = Sprite(fin, "Shellcreeper_Idle.txt");
    xPos = 500;
    yPos = 500;
}

bool Sidestepper:: setSprite(ifstream &fin, string name) {
    return sprite.loadFrame(fin, name.c_str());
}

void Sidestepper::moveRight() {
    xPos += 5;
}

void Sidestepper::moveLeft() {
    xPos -= 5;
}

void Sidestepper::moveDown(){
    if(yPos < 700){
        yPos += 3;
    }
}

void Sidestepper::fall(){
    xPos = 0;
    yPos = 0;
    sprite = Sprite();
}

Sprite Sidestepper::getSprite() const {
    return sprite;
}

int Sidestepper::getXPos() const {
    return xPos;
}

int Sidestepper::getYPos() const {
    return yPos;
}

void Sidestepper::flipped(ifstream &fin) {
    sprite.loadFrame(fin, "Shellcreeper_Flipped.txt");
}

#include "FighterFly.h"
#include "Sprite.hpp"
#include <iostream>

using namespace std;

FighterFly :: FighterFly(ifstream &fin) {
    sprite = Sprite(fin, "FighterFly.txt");
    xPos = 500;
    yPos = 700;
}

bool FighterFly :: setSprite(ifstream &fin, string name) {
    return sprite.loadFrame(fin, name.c_str());
}

void FighterFly :: moveRight() {
    xPos += 1;
}

void FighterFly :: moveLeft() {
    xPos -= 1;
}
//void FighterFly ::jump() {
//    for(int i = 0; i < 1; i++) {
//        yPos -= 1;
//    }

//}

Sprite FighterFly :: getSprite() const {
    return sprite;
}

int FighterFly :: getXPos() const {
    return xPos;
}

int FighterFly :: getYPos() const {
    return yPos;
}


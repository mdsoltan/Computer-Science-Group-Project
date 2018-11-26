//
//  Mario.cpp
//  Mario_Bros
//
//  Created by Mohsen on 11/26/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#include "MohsenMario.hpp"

Mario::Mario(ifstream &fin) {
    sprite = Sprite(fin, "Mario_Idle.txt");
    xPos = 500;
    yPos = 500;
}

bool Mario::setSprite(ifstream &fin, string name) {
    return sprite.loadFrame(fin, name.c_str());
}

void Mario::moveRight() {
    xPos += 10;
}

void Mario::moveLeft() {
    xPos -= 10;
}

Sprite Mario::getSprite() const {
    return sprite;
}

int Mario::getXPos() const {
    return xPos;
}

int Mario::getYPos() const {
    return yPos;
}



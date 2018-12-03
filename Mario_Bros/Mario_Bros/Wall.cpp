//
//  Wall.cpp
//  Mario_Bros
//
//  Created by Mohsen on 11/30/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#include "Wall.hpp"

Wall::Wall(int x, int y, int len) {
    length = len;
    xPos = x;
    yPos = y;
    
}

bool Wall::setSprite(ifstream &fin, string name) {
    bool success = sprite.loadFrame(fin, name.c_str());
    collider.setup(xPos, yPos, sprite.getCol() * length, sprite.getRow(), 'W');
    return success;
}

Sprite Wall::getSprite() const {
    return sprite;
}

CollisionBox Wall::getCollider() const {
    return collider;
}

void Wall::draw(SDL_Plotter &plotter) {
    for(int i = 0; i < length; i++) {
        sprite.draw(plotter, xPos + sprite.getRow()*i, yPos);
    }
}

int Wall::getX() {
    return xPos;
}

int Wall::getY() {
    return yPos;
}

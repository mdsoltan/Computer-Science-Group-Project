//
//  CollisionBox.cpp
//  Mario_Bros
//
//  Created by Mohsen on 11/30/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#include "CollisionBox.hpp"

CollisionBox::CollisionBox() {
    xPos = 0;
    yPos = 0;
    width = 0;
    height = 0;
    underWall = false;
    onWall = false;
    
}

bool CollisionBox::checkCollision(CollisionBox b) {
    int leftB, rightB, topB, bottomB;
    underWall = false;
    onWall = false;
    
    leftB = b.getX();
    rightB = b.getX() + b.getWidth();
    topB = b.getY();
    bottomB = b.getY() + b.getHeight();
    
    if(yPos+height <= topB) {
        return false;
    }
    
    if(yPos >= bottomB) {
        return false;
    }
    
    if(xPos+width <= leftB) {
        return false;
    }
    
    if(xPos >= rightB) {
        return false;
    }
    
    return true;
}

int CollisionBox::getX() const {
    return xPos;
}

int CollisionBox::getY() const {
    return yPos;
}

int CollisionBox::getWidth() const {
    return width;
}

int CollisionBox::getHeight() const {
    return height;
}

void CollisionBox::update(int x, int y) {
    xPos = x;
    yPos = y;
}

void CollisionBox::setup(int x, int y, int w, int h, char t) {
    xPos = x;
    yPos = y;
    height = h;
    width = w;
    type = t;
}

void CollisionBox::draw(SDL_Plotter &plotter) {
    for(int i = xPos; i < xPos + width; i++) {
        for(int j = yPos; j < yPos + height; j++) {
            plotter.plotPixel(i, j, 100, 100, 100);
        }
    }
}

bool CollisionBox::getOnWall() const {
    return onWall;
}
bool CollisionBox::getUnderWall() const {
    return underWall;
}
bool CollisionBox::getUnderEnemy() const {
    return hitByMario;
}

//
//  Mario.cpp
//  Mario_Bros
//
//  Created by Mohsen on 11/26/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#include "MohsenMario.hpp"

Mario::Mario(ifstream &fin) {
    xPos = 500;
    yPos = 500;
    onGround = false;
    gravity = 0.2;
}

bool Mario::setSprite(ifstream &fin, string name) {
    bool success = sprite.loadFrame(fin, name.c_str());
    collider.setup(xPos, yPos, sprite.getCol(), sprite.getRow(), 'M');
    return success;
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

void Mario::moveX(SDL_Plotter &plotter, bool l, bool r) {
    
        if(r) {
            if(xPos >= 1000) {
                xPos = 0;
            } else {
             xPos += 2;
            }
            collider.update(xPos, yPos);
            sprite.setFacingRight(false);
        } else if(l) {
            if(xPos <= 0) {
                xPos = 1000;
            } else {
             xPos -= 2;
            }
            collider.update(xPos, yPos);
            sprite.setFacingRight(true);
        }
}

void Mario::moveY(SDL_Plotter &plotter, bool space) {
    
    if(yVelocity > -3) {
        yVelocity -= gravity;
    }
    
        if(space && onGround) {
            yVelocity = 8;
            onGround = false;
        }
    
    yPos += -yVelocity;
    collider.update(xPos, yPos);
    
    if(yPos < 0) {
        yPos = 0;
    }
}

void Mario::draw(SDL_Plotter &plotter) {
    sprite.draw(plotter, xPos, yPos);
}

void Mario::checkCollisionX(Wall b) {
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

void Mario::checkCollisionY(Wall b) {
    if(collider.checkCollision(b.getCollider())) {
        yPos -= -yVelocity;
        yVelocity = -1;
        collider.update(xPos, yPos);
        onGround = true;
    }
}



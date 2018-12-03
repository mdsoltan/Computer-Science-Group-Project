//
//  Mario.hpp
//  Mario_Bros
//
//  Created by Mohsen on 11/26/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#ifndef Mario_hpp
#define Mario_hpp

#include <stdio.h>
#include <fstream>
#include <algorithm>
#include "Sprite.hpp"
#include "CollisionBox.hpp"
#include "Wall.hpp"

class Mario {
private:
    Sprite sprite;
    int xPos, yPos;
    double gravity, yVelocity;
    bool onGround;
    CollisionBox collider;
public:
    Mario(ifstream &fin);
    
    bool setSprite(ifstream &fin, string name);
    
    void moveX(SDL_Plotter &plotter, bool l, bool r);
    void moveY(SDL_Plotter &plotter, bool space);
    void draw(SDL_Plotter &plotter);
    void setDirection(bool);
    void checkCollisionX(Wall b);
    void checkCollisionY(Wall b);
    
    Sprite getSprite() const;
    int getXPos() const;
    int getYPos() const;
    bool getDirection() const;
};

#endif /* Mario_hpp */

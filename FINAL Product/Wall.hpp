//
//  Wall.hpp
//  Mario_Bros
//
//  Created by Mohsen on 11/30/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include "SDL_Plotter.h"
#include "Sprite.hpp"
#include "CollisionBox.hpp"

class Wall {
private:
    Sprite sprite;
    CollisionBox collider;
    int xPos, yPos, length;
public:
    Wall(int x, int y, int len);
    
    void draw(SDL_Plotter &plotter);
    
    bool setSprite(ifstream &fin, string name);
    int getX();
    int getY();
    
    Sprite getSprite() const;
    CollisionBox getCollider() const;
};

#endif /* Wall_hpp */

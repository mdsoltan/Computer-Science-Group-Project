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
#include "Sprite.hpp"

class Mario {
private:
    Sprite sprite;
    int xPos, yPos;
public:
    Mario(ifstream &fin);
    
    bool setSprite(ifstream &fin, string name);
    
    void moveRight();
    void moveLeft();
    
    Sprite getSprite() const;
    int getXPos() const;
    int getYPos() const;
    
};

#endif /* Mario_hpp */

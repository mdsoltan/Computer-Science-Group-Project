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
    
    void setSprite();
    
    void moveRight(int &x, int &y);
    void moveLeft(int &x, int &y);
    
};

#endif /* Mario_hpp */

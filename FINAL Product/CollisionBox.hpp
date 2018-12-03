//
//  CollisionBox.hpp
//  Mario_Bros
//
//  Created by Mohsen on 11/30/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#ifndef CollisionBox_hpp
#define CollisionBox_hpp

#include <stdio.h>
#include "SDL_Plotter.h"

class CollisionBox {
private:
    int xPos, yPos, width, height;
    char type;
    bool underWall, onWall, hitByMario;
public:
    CollisionBox();
    
    void setup(int x, int y, int w, int h, char t);
    void update(int x, int y);
    void draw(SDL_Plotter &plotter);
    
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    bool getUnderWall() const;
    bool getOnWall() const;
    bool getUnderEnemy() const;
    
    bool checkCollision(CollisionBox b);
    
};

#endif /* CollisionBox_hpp */

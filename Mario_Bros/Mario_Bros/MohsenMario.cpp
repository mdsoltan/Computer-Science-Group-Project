//
//  Mario.cpp
//  Mario_Bros
//
//  Created by Mohsen on 11/26/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#include "Mario.hpp"

Mario::Mario(ifstream &fin) {
    sprite = Sprite(fin, "Mario_Idle.txt");
    xPos = 500;
    yPos = 500;
}

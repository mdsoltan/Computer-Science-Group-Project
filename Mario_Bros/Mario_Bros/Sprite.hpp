//
//  Sprite.hpp
//  Mario_Bros
//
//  Created by Mohsen on 11/14/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "SDL_Plotter.h"

//OSX Libraries
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2/SDL_thread.h>

//Windows Library
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_mixer.h>

using namespace std;

struct Pixel {
    int r = 0;
    int g = 0;
    int b = 0;
    
    Pixel() {
        r = 0;
        g = 0;
        b = 0;
    }
    
    Pixel (int r_new, int g_new, int b_new) {
        r = r_new;
        g = g_new;
        b = b_new;
    }
};

class Sprite {
private:
    int row, col;
    vector<vector<Pixel>> pixel_vector;
    bool facingRight, upsideDown;
    
public:
    Sprite();
//    Sprite(ifstream &fin, string name);
    bool loadFrame(ifstream &fin, string name);
    
    void draw(SDL_Plotter &plotter, int x, int y) const;
    
    int getRow() const;
    int getCol() const;
    Pixel getPixel(int r, int c) const;
    bool getFacingRight() const;
    bool getUpsideDown() const;
    
    void setFacingRight(bool);
    void setUpsideDown(bool);
    
};


#endif /* Sprite_hpp */

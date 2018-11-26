//
//  Sprite.cpp
//  Mario_Bros
//
//  Created by Mohsen on 11/14/18.
//  Copyright © 2018 [Insert Name Here]. All rights reserved.
//

#include "Sprite.hpp"

Sprite::Sprite() {
    row = 0;
    col = 0;
}

//***** Uses main's ifstream to read from the text file specified in "name" *****
Sprite::Sprite(ifstream &fin, string name) {
    int r, g, b;
    
    fin.open(name.c_str());
    if(fin.fail()) {
        exit(1);
    }
    
    fin >> col >> row;
    
    pixel_vector.resize(row);
    for(int i = 0; i < row; i++) {
        pixel_vector[i].resize(col);
        for(int j = 0; j < col; j++) {
            fin >> r >> g >> b;
            Pixel a(r, g, b);
            pixel_vector[i][j] = a;
        }
    }
    
    fin.close();
}

//***** Uses main's ifstream to read from the text file specified in "name" *****
bool Sprite::loadFrame(ifstream &fin, string name) {
    int r, g, b;
    
    fin.open(name.c_str());
    if(fin.fail()) {
        return false;
    }
    
    fin >> col >> row;
    
    pixel_vector.resize(row);
    for(int i = 0; i < row; i++) {
        pixel_vector[i].resize(col);
        for(int j = 0; j < col; j++) {
            fin >> r >> g >> b;
            Pixel a(r, g, b);
            pixel_vector[i][j] = a;
        }
    }
    
    fin.close();
    
    return true;
}

//***** Draws Sprite normally *****
void Sprite::draw(SDL_Plotter &plotter, int x, int y) const{
    int r, g, b;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            r = pixel_vector[i][j].r;
            g = pixel_vector[i][j].g;
            b = pixel_vector[i][j].b;
            plotter.plotPixel(j + x, i + y, r, g, b);
        }
    }
}

//***** Draws Sprite backwards (if it was facing right, it now faces left) *****
void Sprite::drawReverse(SDL_Plotter &plotter, int x, int y) const{
    int r, g, b;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            r = pixel_vector[i][j].r;
            g = pixel_vector[i][j].g;
            b = pixel_vector[i][j].b;
            plotter.plotPixel(row-j + x, i + y, r, g, b);
        }
    }
}

//***** Draws Sprite upside-down *****
void Sprite::drawFlipped(SDL_Plotter &plotter, int x, int y) const{
    int r, g, b;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            r = pixel_vector[i][j].r;
            g = pixel_vector[i][j].g;
            b = pixel_vector[i][j].b;
            plotter.plotPixel(j + x, row-i + y, r, g, b);
        }
    }
}

//***** Draws Sprite backwards and upside down *****
void Sprite::drawRevFlip(SDL_Plotter &plotter, int x, int y) const{
    int r, g, b;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            r = pixel_vector[i][j].r;
            g = pixel_vector[i][j].g;
            b = pixel_vector[i][j].b;
            plotter.plotPixel(col-j + x, row-i + y, r, g, b);
        }
    }
}

//***** Used in draw functions *****
int Sprite::getRow() const {
    return row;
}

//***** Used in draw functions *****
int Sprite::getCol() const {
    return col;
}

//***** Used in draw functions *****
Pixel Sprite::getPixel (int r, int c) const {
    return pixel_vector[r][c];
}

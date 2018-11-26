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

int Sprite::getRow() const {
    return row;
}

int Sprite::getCol() const {
    return col;
}

Pixel Sprite::getPixel (int r, int c) const {
    return pixel_vector[r][c];
}

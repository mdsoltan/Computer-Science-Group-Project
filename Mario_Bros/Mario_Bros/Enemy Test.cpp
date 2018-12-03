//
// Created by etber on 12/2/2018.
//

#include <iostream>
#include <fstream>

#include "SDL_Plotter.h"
#include "Sprite.hpp"
#include "Shellcreeper.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(1000,1000);
    ifstream sfin;
    ifstream sfin2;
    bool stopped = false;
    int x = 0, y = 0;
    int R,G,B;
    s_movement koopa(sfin);
    bool shouldMoveBack = false;
    bool isFlipped = false;
    bool isDead = false;

    g.initSound("Test_Song.mp3");
    g.playSound("Test_Song.mp3");
    while (!g.getQuit())
    {

        if(!stopped){
            R = 200;
            G = 30;
            B = 60;

            for(int i = 0; i < 1000; i++) {
                for(int j = 0; j < 1000; j++)
                    g.plotPixel(j, i, 0, 0, 0);
            }

      }

        if(g.kbhit()) {
            bool temp = false;
            if(g.getKey() == '1' && shouldMoveBack == true && isFlipped == false){
                koopa.moveLeft();
                koopa.getSprite().draw(g, koopa.getXPos(), koopa.getYPos());
                shouldMoveBack = false;
                temp = true;
            }
            if(g.getKey() == '1' && shouldMoveBack == false && temp == false && isFlipped == false) {
                koopa.moveLeft();
                koopa.getSprite().drawReverse(g, koopa.getXPos(), koopa.getYPos());
                shouldMoveBack = true;
            }
            if(g.getKey() == '2' && isFlipped == true){

                isDead = true;
            }
            if(g.getKey() == '2' && isFlipped == false) {
                koopa.flipped(sfin);
                koopa.getSprite().draw(g, koopa.getXPos(), koopa.getYPos());
                //koopa.moveDown();
                isFlipped = true;
            }

        }
        if(shouldMoveBack == false && isFlipped == false) {
            koopa.moveRight();
            koopa.getSprite().draw(g, koopa.getXPos(), koopa.getYPos());
            koopa.moveDown();
        }
        if(shouldMoveBack == true && isFlipped == false){
            koopa.moveLeft();
            koopa.getSprite().drawReverse(g, koopa.getXPos(), koopa.getYPos());
            koopa.moveDown();
        }
        if(isFlipped == true && isDead == false){
            koopa.getSprite().draw(g, koopa.getXPos(), koopa.getYPos());
            koopa.moveDown();
        }
        if(isDead == true){

            while(koopa.getYPos() <= 1000){
                for(int i = 0; i < 1000; i++) {
                    for(int j = 0; j < 1000; j++)
                        g.plotPixel(j, i, 0, 0, 0);
                }
                koopa.fall();
                koopa.getSprite().draw(g, koopa.getXPos(), koopa.getYPos());
                g.update();
            }

        }

        g.update();
    }
}



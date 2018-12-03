//
// Created by etber on 12/2/2018.
//

#include <iostream>
#include <fstream>

#include "SDL_Plotter.h"
#include "Sprite.hpp"
#include "Shellcreeper.h"
#include "Sidestepper.h"

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(1000,1000);
    ifstream sfin;
    ifstream cfin;
    bool stopped = false;
    int x = 0, y = 0;
    int R,G,B;
    s_movement koopa(sfin);
    Sidestepper crab(cfin);
    bool shouldMoveBack = false;
    bool isFlipped = false;

    bool shouldMoveBack2 = false;
    bool isHit = false;
    bool isFlipped2 = false;
    
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
                koopa.fall();
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
        if(isFlipped == true){
            koopa.getSprite().draw(g, koopa.getXPos(), koopa.getYPos());
            koopa.moveDown();
        }


        if(g.kbhit()) {
            bool temp = false;
            if(g.getKey() == '3' && shouldMoveBack2 == true && isFlipped2 == false){
                crab.moveLeft();
                crab.getSprite().drawFlipped(g, crab.getXPos(), crab.getYPos());
                shouldMoveBack2 = false;
                temp = true;
            }
            if(g.getKey() == '3' && shouldMoveBack == false && temp == false && isFlipped2 == false) {
                crab.moveLeft();
                crab.getSprite().drawRevFlip(g, crab.getXPos(), crab.getYPos());
                shouldMoveBack2 = true;
            }
            if(g.getKey() == '4' && isFlipped2 == true){
                crab.fall();
            }
            if(g.getKey() == '4' && isFlipped2 == false && isHit == true) {
                crab.flipped(cfin);
                crab.getSprite().drawFlipped(g, crab.getXPos(), crab.getYPos());
                //koopa.moveDown();
                isFlipped2 = true;
            }
            if(g.getKey() == '4' && isFlipped2 == false && isHit == false) {
                isHit = true;
            }

        }
        if(shouldMoveBack2 == false && isFlipped2 == false) {
            crab.moveRight();
            crab.getSprite().drawFlipped(g, crab.getXPos(), crab.getYPos());
            crab.moveDown();
        }
        if(shouldMoveBack2 == true && isFlipped2 == false){
            crab.moveLeft();
            crab.getSprite().drawRevFlip(g, crab.getXPos(), crab.getYPos());
            crab.moveDown();
        }
        if(isFlipped2 == true){
            crab.getSprite().drawFlipped(g, crab.getXPos(), crab.getYPos());
            crab.moveDown();
        }


        g.update();
    }
}



#include <iostream>
#include <fstream>

#include "SDL_Plotter.h"
#include "Sprite.hpp"
#include "slipice.hpp"
#include "MohsenMario.hpp"
#include "FighterFly.h"

using namespace std;

/*
 * This main essentially just sprinkles pixels all over the screen.
 * Booth originally wrote this, but you can use this as a reference
 * for your own classes/functions as you plot out where characters and
 * enemies are on screen.
 */
int main(int argc, char ** argv)
{
    SDL_Plotter g(1000,1000);
    ifstream fin;
    ifstream sfin;
    ifstream ffin;
    bool stopped = false;
    int x = 0, y = 0;
    int R,G,B;
    Mario mario(fin);
    FighterFly Fly(ffin);
    slipice Slip(sfin);

    bool marioLoad = mario.setSprite(fin, "Mario_Idle.txt");
    bool FlyLoad = Fly.setSprite(ffin, "FighterFly.txt");
    bool Slipload = Slip.setSprite(sfin, "slipice.txt");

    while (!g.getQuit())
    {


        if(!stopped){
            R = 0;
            G = 0;
            B = 0;

            for(int i = 0; i < 1000; i++) {
                for(int j = 0; j < 1000; j++)
                    g.plotPixel(j, i, 255, 255, 255);
            }

            for(int i = 0; i < 1000; i++) {
                for(int j = 0; j < 1000; j++)
                    g.plotPixel(j + x, i + y, R, G, B);
            }


            if(!marioLoad) {
                cout << "Sprite Load Failed!" << endl;
                exit(1);
            }

            if(!FlyLoad){
                cout << "F-Fly load failed!" << endl;
                exit(2);
            }
            if(!Slipload){
                cout << "Slip load failed!"<<endl;
                exit(3);
            }



        }

        if(g.kbhit()) {
            if(g.getKey() == RIGHT_ARROW) {
                mario.moveRight();
                mario.getSprite().draw(g, mario.getXPos(), mario.getYPos());
            } else if(g.getKey() == LEFT_ARROW) {
                mario.moveLeft();
                mario.getSprite().drawReverse(g, mario.getXPos(), mario.getYPos());
            }
        } else {
            mario.getSprite().draw(g, mario.getXPos(), mario.getYPos());
        }

        if(g.kbhit()) {
            if(g.getKey() == '1') {
                Fly.moveLeft();
                Fly.getSprite().draw(g, Fly.getXPos(), Fly.getYPos());
            }

        } else {

            Fly.moveRight();
//            Fly.jump();
            Fly.getSprite().draw(g, Fly.getXPos(), Fly.getYPos());
        }
        if(g.kbhit()) {
            if(g.getKey() == '1') {
                Slip.moveLeft();
                Slip.getSprite().draw(g, Slip.getXPos(),Slip.getYPos());
            }

        } else  {

            Slip.moveRight();
//            Fly.jump();
            Slip.getSprite().draw(g, Slip.getXPos(), Slip.getYPos());
        }

        g.update();
    }
}
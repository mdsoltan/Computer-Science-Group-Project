#include <iostream>
#include <fstream>

#include "SDL_Plotter.h"
#include "Sprite.hpp"

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
    bool stopped = false;
    int x = 0, y = 0;
    int R,G,B;
    Sprite Mario;
    
    bool marioLoad = Mario.loadFrame(fin, "Mario_Idle.txt");
    
    while (!g.getQuit())
    {
        
        
        if(!stopped){
            R = 200;
            G = 30;
            B = 60;

            for(int i = 0; i < 1000; i++) {
                for(int j = 0; j < 1000; j++)
                    g.plotPixel(j, i, 255, 255, 255);
            }

            for(int i = 0; i < 100; i++) {
                for(int j = 0; j < 100; j++)
                    g.plotPixel(j + x, i + y, R, G, B);
            }
            
            
            if(marioLoad) {
                Mario.draw(g);
            }

                }

        if(g.kbhit()) {
            if(g.getKey() == RIGHT_ARROW)
                x += 10;
            if(g.getKey() == LEFT_ARROW)
                x -= 10;
            if(g.getKey() == DOWN_ARROW)
                y += 10;
            if(g.getKey() == UP_ARROW)
                y -= 10;
        }
        
        g.update();
    }
}

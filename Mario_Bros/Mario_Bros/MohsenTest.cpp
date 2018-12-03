#include <iostream>
#include <fstream>

#include "SDL_Plotter.h"
#include "Sprite.hpp"
#include "MohsenMario.hpp"
#include "Shellcreeper.h"
#include "Wall.hpp"

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
    bool keyRight = false, keyLeft = false, keySpace = false;
    Mario mario(fin);
    s_movement shellcreeper(fin);
    Wall platform(50, 100, 50);
    Wall platform2(550, 100, 50);
    Wall platform3(300, 250, 50);
    Wall platform4(50, 400, 50);
    Wall platform5(550, 400, 50);
    Wall platform6(300, 550, 50);
    Wall brick1(0, 700, 67);
    Wall pipeIn(968, 682, 1);
    Wall pipeIn2(0, 682, 1);
    
    pipeIn.setSprite(fin, "Pipe_In.txt");
    pipeIn2.setSprite(fin, "Pipe_In.txt");
    pipeIn2.getSprite().setFacingRight(false);
    shellcreeper.setSprite(fin, "Shellcreeper_Idle.txt");
    mario.setSprite(fin, "Mario_Idle.txt");
    platform.setSprite(fin, "Platform.txt");
    brick1.setSprite(fin, "Brick.txt");
    platform2.setSprite(fin, "Platform.txt");
    platform3.setSprite(fin, "Platform.txt");
    platform4.setSprite(fin, "Platform.txt");
    platform5.setSprite(fin, "Platform.txt");
    platform6.setSprite(fin, "Platform.txt");
    
    while (!g.getQuit())
    {
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++)
                g.plotPixel(j, i, 0, 0, 0);
        }
        
        platform.draw(g);
        platform2.draw(g);
        platform3.draw(g);
        platform5.draw(g);
        platform4.draw(g);
        platform6.draw(g);
        brick1.draw(g);
        pipeIn.draw(g);
        pipeIn2.draw(g);
        
        keySpace = false;
        keyRight = false;
        keyLeft = false;
        
        g.kbhit(); 
        g.getKey(keyLeft, keyRight, keySpace);

        mario.moveX(g, keyLeft, keyRight);
        mario.moveY(g, keySpace);
        mario.checkCollisionY(brick1);
        mario.checkCollisionY(platform);
        mario.checkCollisionY(platform2);
        mario.checkCollisionY(platform3);
        mario.checkCollisionY(platform4);
        mario.checkCollisionY(platform5);
        mario.checkCollisionY(platform6);
        
        shellcreeper.moveX();
        shellcreeper.moveDown();
        shellcreeper.checkCollisionY(brick1);
        shellcreeper.checkCollisionY(platform);
        shellcreeper.checkCollisionY(platform2);
        shellcreeper.checkCollisionY(platform3);
        shellcreeper.checkCollisionY(platform4);
        shellcreeper.checkCollisionY(platform5);
        shellcreeper.checkCollisionY(platform6);
        shellcreeper.inPipe(pipeIn);
        shellcreeper.inPipe(pipeIn2);
        
        shellcreeper.draw(g);
        mario.draw(g);
        
        g.update();
    }
}

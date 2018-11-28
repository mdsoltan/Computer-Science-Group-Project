//
// Created by etber on 11/26/2018.
//

#include "Shellcreeper.h"
#include <iostream>

using namespace std;

s_movement::s_movement(ifstream &fin) {
    sprite = Sprite(fin, "Shellcreeper.txt");
    xPos = 500;
    yPos = 500;
}

bool s_movement::setSprite(ifstream &fin, string name) {
    return sprite.loadFrame(fin, name.c_str());
}

void s_movement::moveRight() {
    xPos += 5;
}

void s_movement::moveLeft() {
    xPos -= 5;
}

Sprite s_movement::getSprite() const {
    return sprite;
}

int s_movement::getXPos() const {
    return xPos;
}

int s_movement::getYPos() const {
    return yPos;
}

void s_movement.flipped(ifstream &fin){
    sprite.loadFrame(fin, "ShellcreeperFlipped.txt")
}



void s_movement::move(SDL_Surface *sprite, SDL_Rect rcSprite, SDL_Window* &window, SDL_Surface* &screen,
                      const int SCREEN_WIDTH, const int SCREEN_HEIGHT, const int SPRITE_SIZE,
                      const int SPRITE_HEIGHT)
{
    bool shouldStop = false;
    SDL_Event k;
    bool atBottom = false;
    bool toEnd = false;
    const Uint8* state;
    if(toEnd == false){
        if (SDL_PollEvent(&k) == 1 && k.type == SDL_TEXTINPUT) {
            cout << "Key pressed" << endl;
        }
        state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_2]) {
            if (shouldStop == false) {
                shouldStop = true;
            }
            else {
                shouldStop = false;
            }
        }
        if (shouldStop == false) {
            //Movement
            state = SDL_GetKeyboardState(NULL);
            if (state[SDL_SCANCODE_1]) {
                //cout << "Detected 1" << endl;
                SDL_FillRect(screen, NULL, NULL);
                sprite = SDL_LoadBMP("Walking_1_Reversed.BMP");
                rcSprite.x -= 1;
                //Slows down the shellcreeper
                SDL_Delay(5);
            } else {
                //cout << "Should be moving" << endl;
                SDL_FillRect(screen, NULL, NULL);
                rcSprite.x += 1;
                sprite = SDL_LoadBMP("Walking_1.BMP");
                SDL_Delay(5);

            }
            //Screen warp
            if (rcSprite.x < 0) {
                if(atBottom == false){
                    rcSprite.x = SCREEN_WIDTH - SPRITE_SIZE;
                }
                if(atBottom == true){
                    toEnd = true;
                }
            } else if (rcSprite.x > SCREEN_WIDTH - SPRITE_SIZE) {
                if(atBottom == false) {
                    rcSprite.x = 0;
                }
                if(atBottom == true){
                    toEnd = true;
                }
            }
            /*if (rcSprite.y < 0) {
                rcSprite.y = 0;
            } else if (rcSprite.y > SCREEN_HEIGHT - SPRITE_SIZE) {
                rcSprite.y = 0;
            }*/

            SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
        } else {
            //Shellcreeper flips over
            sprite = SDL_LoadBMP("Flipped.BMP");
            SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
        }
        //Always falls
        if (rcSprite.y < SCREEN_HEIGHT - SPRITE_HEIGHT) {
            rcSprite.y += 3;
        }
        //Detects if it got to the end of the screen
        if(rcSprite.y == SCREEN_HEIGHT-SPRITE_HEIGHT-1) {
            atBottom = true;
        }
    }
    else{
        SDL_FillRect(screen, NULL, 0x000000);
        SDL_FreeSurface(sprite);
    }
}



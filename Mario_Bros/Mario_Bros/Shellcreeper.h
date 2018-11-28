//
// Created by etber on 11/26/2018.
//

#ifndef ENEMY_SHELLCREEPER_2_S_MOVEMENT_H
#define ENEMY_SHELLCREEPER_2_S_MOVEMENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class s_movement {
    private:
        Sprite sprite;
        int xPos, yPos;
    public:
        Shellcreeper(ifstream &fin);
        void move(SDL_Surface* sprite, SDL_Rect rcSprite, SDL_Window* &window, SDL_Surface* &screen,
                const int SCREEN_WIDTH, const int SCREEN_HEIGHT, const int SPRITE_SIZE, const int SPRITE_HEIGHT);
        bool setSprite(ifstream &fin, string name);

        void moveRight();
        void moveLeft();
        void flipped(ifstream &fin);

        Sprite getSprite() const;
        int getXPos() const;
        int getYPos() const;

};


#endif //ENEMY_SHELLCREEPER_2_S_MOVEMENT_H

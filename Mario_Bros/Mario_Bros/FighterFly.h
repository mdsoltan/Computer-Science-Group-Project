
#ifndef AH_HA_FighterFly_H
#define AH_HA_FighterFly_H

#include <SDL2/SDL.h>
#include "Sprite.hpp"
class FighterFly {
private:
    Sprite sprite;
    int xPos, yPos;
public:
    FighterFly(ifstream &fin);

    bool setSprite(ifstream &fin, string name);

    void moveRight();
    void moveLeft();

    Sprite getSprite() const;
    int getXPos() const;
    int getYPos() const;

};


#endif //ENEMY_SHELLCREEPER_2_S_MOVEMENT_H
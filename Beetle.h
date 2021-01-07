#ifndef BEETLE_H
#define BEETLE_H

#include "Player.h"

/** CLASS: Beetle
 * Simulates a beetle that is invincible, gets the player stuck
 * Derived from Player
 *
 * ATTRIBUTES:
 * -direction: int
 *      Denotes which direction (up/down) the character will move
 *
 * METHODS:
 * +move():
 *      Moves the character based on its design
 */
class Beetle : public Player
{
private:
    int direction;

public:
    Beetle(int = 0);
    virtual ~Beetle();
    void move();
};

#endif
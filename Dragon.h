#ifndef DRAGON_H
#define DRAGON_H

#include "Player.h"

/** CLASS: Dragon
 * Simulates a dragon that is guarding its treasure, instantly kills Heroes
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
class Dragon : public Player
{
private:
    int direction;

public:
    Dragon();
    virtual ~Dragon();
    void move();
};

#endif
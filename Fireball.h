#ifndef FIREBALL_H
#define FIREBALL_H

#include "Player.h"

/** CLASS: Fireball
 * Simulates a Fireball being fired from the Dragon, movement differs based on size
 * Derived from Player
 *
 * ATTRIBUTES:
 * -length: int
 *      Indicates the length of the fireball's trail
 *
 * METHODS:
 * +move():
 *      Moves the character based on its design
 */
class Fireball : public Player
{
private:
    int length;

public:
    Fireball(int);
    virtual ~Fireball();
    int getLength();
    void move();
};

#endif
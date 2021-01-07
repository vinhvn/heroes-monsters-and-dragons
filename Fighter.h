#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"

/** CLASS: Fighter
 * Simulates one of various standard fighters, including dorcs, borcs, and porcs
 * Derived from Player
 *
 * ATTRIBUTES:
 *
 * METHODS:
 * +move():
 *      Moves the character based on its design
 */
class Fighter : public Player
{
private:
public:
    Fighter();
    virtual ~Fighter();
    void move();
};

#endif
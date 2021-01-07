#ifndef AMETHYST_H
#define AMETHYST_H

#include "Player.h"

/** CLASS: Amethyst
 * Simulates a false Emerald that warps the player to the start
 * Derived from Player
 *
 * ATTRIBUTES:
 *
 * METHODS:
 * +move():
 *      Moves the character based on its design
 */
class Amethyst : public Player
{
private:
public:
    Amethyst();
    virtual ~Amethyst();
    void move();
};

#endif
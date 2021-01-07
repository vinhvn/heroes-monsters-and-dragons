#ifndef ALIEN_H
#define ALIEN_H

#include "Player.h"

/** CLASS: Alien
 * Simulates an alien mob that dashes and pierces armour
 * Derived from Player
 *
 * ATTRIBUTES:
 *
 * METHODS:
 * +move():
 *      Moves the character based on its design
 */
class Alien : public Player
{
private:
public:
    Alien();
    virtual ~Alien();
    void move();
};

#endif
#ifndef HERO_H
#define HERO_H

#include "Player.h"

/** CLASS: Hero
 * Simulates a Hero, who fights against monsters
 * Derived from Player
 *
 * ATTRIBUTES:
 * -stuck: bool
 *      Indicates whether the hero is currently stuck or not
 * -armour: int
 *
 * METHODS:
 * +isStuck(): bool
 * +isHero(): bool
 * +interact(inout: Player *): void
 *      Simulates an interaction between hero and given player
 * +move():
 *      Moves the character based on its design
 */
class Hero : public Player
{
private:
    bool stuck;
    int armour;

public:
    Hero(char = 'T', int = 0, int = 0);
    virtual ~Hero();
    int getArmour();
    bool isStuck();
    void setStuck(bool);
    bool isHero();
    void interact(Player *);
    void move();
};

#endif
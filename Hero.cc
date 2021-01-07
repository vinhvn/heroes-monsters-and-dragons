#include <iostream>
using namespace std;

#include "Hero.h"
#include "Fireball.h"
#include "constants.h"
#include "random.h"

Hero::Hero(char a, int str, int arm) : Player(a, 0, random(MAX_HEIGHT), 15, str), stuck(false), armour(arm)
{
}

Hero::~Hero()
{
}

int Hero::getArmour() { return armour; }
bool Hero::isStuck() { return stuck; }
void Hero::setStuck(bool b) { this->stuck = b; }
bool Hero::isHero() { return true; }

void Hero::interact(Player *other)
{
    // if dead, can't interact
    if (!isAlive())
        return;

    char avatar = other->getAvatar();
    int x, y;
    getPos(x, y);

    // check y positions line up
    if (y != other->getY())
        return;

    // if not a fireball or alien, check x normally
    if (avatar != 'O' && avatar != '@')
    {
        if (x != other->getX())
            return;
    }
    // if it's a fireball, check trail
    else if (avatar == 'O')
    {
        if (x < other->getX() || x > other->getX() + ((Fireball *)other)->getLength())
            return;
    }
    // if it's an alien, check tail
    else
    {
        if (x < other->getX() || x > other->getX() + 1)
            return;
    }

    // if we hit a dragon, die
    if (avatar == 'D')
        setHealth(0);
    // if we hit a beetle, get stuck
    else if (avatar == 'w')
        setStuck(true);
    // if we hit an amethyst, go back
    else if (avatar == '*')
    {
        other->setHealth(0);
        setPos(0, random(MAX_HEIGHT));
    }
    // otherwise, enter a fight... if not a hero
    else if (!other->isHero())
    {
        // hero takes a hit, aliens ignore armour
        if (avatar == '@')
            setHealth(getHealth() - other->getStrength());
        else
        {
            // calculate enemy damage w/ armour, readjust if negative
            int damage = other->getStrength() - getArmour();
            if (damage < 0)
                damage = 0;
            setHealth(getHealth() - damage);
        }
        // monster takes a hit
        other->setHealth(other->getHealth() - getStrength());
    }
}

void Hero::move()
{
    // if we're dead, can't do much
    if (!isAlive())
        return;
    // if stuck, skip a turn
    if (isStuck())
    {
        setStuck(false);
        return;
    }
    // else, let's move
    int x, y;
    getPos(x, y);
    // go right
    x += 1;
    // go up/down randomly
    int choice = random(3);
    if (choice == 1)
        y -= 1;
    if (choice == 2)
        y += 1;
    // wrap around and bounds checking
    if (x >= MAX_WIDTH)
        x = MAX_WIDTH - 1;
    if (y < 0)
        y = 0;
    else if (y >= MAX_HEIGHT)
        y = MAX_HEIGHT - 1;
    // make the move
    setPos(x, y);
}

#include <iostream>
using namespace std;

#include "Fighter.h"
#include "constants.h"
#include "random.h"

Fighter::Fighter() : Player('x', MAX_WIDTH - 2, random(MAX_HEIGHT), 5, -1)
{
    // randomly determine whether they are dorc/borc/porc
    int choice = random(3);
    // set their avatar and strength as well
    if (choice == 0)
    {
        // dorc
        setAvatar('d');
        setStrength(6 + random(3));
    }
    else if (choice == 1)
    {
        // borc
        setAvatar('b');
        setStrength(8 + random(4));
    }
    else
    {
        // porc
        setAvatar('p');
        setStrength(4 + random(2));
    }
}

Fighter::~Fighter()
{
}

void Fighter::move()
{
    int x, y;
    getPos(x, y);
    // move left
    x -= 1;
    // move up/down randomly
    int choice = random(3);
    if (choice == 1)
        y -= 1;
    if (choice == 2)
        y += 1;
    // go off left side? just die
    if (x < 0)
    {
        setHealth(0);
        return;
    }
    // bounds checking
    if (y < 0)
        y = 0;
    else if (y >= MAX_HEIGHT)
        y = MAX_HEIGHT - 1;
    // move
    setPos(x, y);
}

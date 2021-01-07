#include <iostream>
using namespace std;

#include "Alien.h"
#include "constants.h"
#include "random.h"

Alien::Alien() : Player('@', MAX_WIDTH - 2, random(MAX_HEIGHT), 20, 10)
{
}

Alien::~Alien()
{
}

void Alien::move()
{
    int x, y;
    getPos(x, y);
    // go left
    x -= 2;
    // must go either up or down
    int choice = random(2);
    y += (choice == 0) ? 1 : -1;
    // wrap around and warp
    if (x < 0)
        x = MAX_WIDTH - 2;
    if (y < 0)
        y = MAX_HEIGHT - 1;
    else if (y >= MAX_HEIGHT)
        y = 0;
    // make your move
    setPos(x, y);
}

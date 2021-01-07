#include <iostream>
using namespace std;

#include "Beetle.h"
#include "constants.h"
#include "random.h"

Beetle::Beetle(int x) : Player('w', x, random(MAX_HEIGHT), 100, 0)
{
    // choose to either go up or down
    direction = (random(2) == 0) ? 1 : -1;
}

Beetle::~Beetle()
{
}

void Beetle::move()
{
    int y = getY();
    // move up/down
    y += direction;
    // wrap around
    if (y < 0)
        y = MAX_HEIGHT - 1;
    else if (y >= MAX_HEIGHT)
        y = 0;
    // move
    setY(y);
}

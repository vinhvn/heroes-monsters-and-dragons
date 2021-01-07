#include <iostream>
using namespace std;

#include "Dragon.h"
#include "constants.h"

Dragon::Dragon() : Player('D', MAX_WIDTH - 1, (MAX_HEIGHT / 2), 100, 100), direction(1)
{
}

Dragon::~Dragon()
{
}

void Dragon::move()
{
    int y = getY();
    // move up/down
    y += direction;
    // reverse direction
    if (y <= 0 || y >= MAX_HEIGHT - 1)
        direction *= -1;
    // move
    setY(y);
}

#include <iostream>
using namespace std;

#include "Amethyst.h"
#include "constants.h"
#include "random.h"

Amethyst::Amethyst() : Player('*', MAX_WIDTH / 3 + random(MAX_WIDTH / 2), random(MAX_HEIGHT), 1, 0)
{
}

Amethyst::~Amethyst()
{
}

void Amethyst::move()
{
    int y = getY();
    // move up/down... occasionally
    int choice = random(40);
    // 5% chance of moving
    if (choice <= 1)
        y += (choice == 0) ? 1 : -1;
    // stay within bounds
    if (y < 0)
        y = 0;
    else if (y >= MAX_HEIGHT)
        y = MAX_HEIGHT - 1;
    // move
    setY(y);
}

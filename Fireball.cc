#include <iostream>
using namespace std;

#include "Fireball.h"
#include "constants.h"
#include "random.h"

Fireball::Fireball(int y) : Player('O', 0, y, 1, 4), length(1 + random(3))
{
    // make room for its tail
    setX(MAX_WIDTH - length - 1);
}

Fireball::~Fireball()
{
}

int Fireball::getLength() { return length; }

void Fireball::move()
{
    int x = getX();
    // move left based on tail
    x -= getLength() + 1;
    // go off map? die
    if (x < 0)
    {
        setHealth(0);
        return;
    }
    // move
    setX(x);
}

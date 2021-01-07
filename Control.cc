#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <iterator>
#include "unistd.h"

#include "Control.h"
#include "Game.h"
#include "Player.h"
#include "Hero.h"
#include "Dragon.h"
#include "Beetle.h"
#include "Amethyst.h"
#include "constants.h"
#include "random.h"

#define REFRESH

void Control::launch()
{
    // initialize the characters
    initPlayers();

#ifdef REFRESH
    system("clear");
#endif
    // display initial board
    view.update(game);
    view.display();
    cout << endl;

    while (1)
    {
        // add a delay between each iteration
        usleep(DELAY * 1000);

#ifdef REFRESH
        system("clear");
#endif
        // simulate game
        game.generate();
        game.move();
        game.update();
        view.update(game);
        view.display();
        cout << endl;
        // if a game over condition is met, break
        if (game.gameOver())
            break;
    }
}

// initializes the game with various enemies
void Control::initPlayers()
{
    game.add(new Hero('T', 3, 3));
    game.add(new Hero('H', 5, 1));
    game.add(new Dragon());
    game.add(new Beetle(8 + random(8)));
    game.add(new Beetle(16 + random(8)));
    game.add(new Beetle(24 + random(8)));
    game.add(new Amethyst());
}

#ifndef CONTROL_H
#define CONTROL_H

#include "Game.h"
#include "View.h"

/**CLASS: Control
 * Controls the main program flow
 *
 * ATTRIBUTES:
 * -game: Game
 * -view: View
 *
 * METHODS:
 * +launch(): void
 *      Launches the main program
 * -initPlayers(): void
 *      Populates the game with its initial characters
 */
class Control
{
private:
    Game game;
    View view;
    void initPlayers();

public:
    void launch();
};

#endif
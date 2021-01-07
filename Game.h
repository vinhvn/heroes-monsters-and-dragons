#ifndef GAME_H
#define GAME_H

#include <list>
#include "Grid.h"
#include "Player.h"

/**CLASS: Game
 * Simulates a single game w/ logic, controls turns and manages players
 *
 * ATTRIBUTES:
 * -grid: Grid<char>
 *      Stores the display for our game
 * -players: list<Player *>
 *      Stores a list of player pointers
 *
 * METHODS:
 * +add(in: Player *): void
 *      Adds a given player to the end of the list
 * +generate(): void
 *      Simulates a 60% chance of spawning new enemies
 * +move(): void
 *      Simulates a turn on the board where all players make a move
 * +update(): void
 *      Checks for deaths and updates players accordingly
 * +gameOver(): bool
 *      Checks if game over conditions have been met, returns true if so
 */
class Game
{
private:
    list<Player *> players;

public:
    ~Game();
    list<Player *> *getPlayers();
    void add(Player *);
    void generate();
    void move();
    void update();
    bool gameOver();
};

#endif
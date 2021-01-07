#ifndef VIEW_H
#define VIEW_H

#include "Grid.h"
#include "Game.h"

/**CLASS: View
 * Handles displaying the game to the console
 *
 * ATTRIBUTES:
 * -grid: Grid<char>
 *      char specialization of 2D array collection class
 *
 * METHODS:
 * +update(in: Game&)
 *      Updates stored grid with game players
 * +display(): void
 */
class View
{
private:
    Grid<char> grid;

public:
    View();
    void update(Game &);
    void display();
};

#endif
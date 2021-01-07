#include <iostream>
using namespace std;
#include <list>

#include "View.h"
#include "Game.h"
#include "Player.h"
#include "Fireball.h"
#include "constants.h"

View::View() : grid(MAX_HEIGHT, MAX_WIDTH)
{
}

void View::update(Game &game)
{
    int x, y, trail;
    char avatar;
    list<Player *>::iterator ptr;
    list<Player *> *players;

    // get our players
    players = game.getPlayers();
    // clear the grid
    grid.refresh();
    // populate the grid with our players
    for (ptr = players->begin(); ptr != players->end(); ptr++)
    {
        (*ptr)->getPos(x, y);
        avatar = (*ptr)->getAvatar();
        // place the avatar at given x,y
        grid[y][x] = avatar;

        // if fireball, add trail
        if (avatar == 'O')
        {
            Fireball *f = dynamic_cast<Fireball *>(*ptr);
            if (f != 0)
            {
                trail = f->getLength();
                for (int i = 0; i < trail; i++)
                    grid[y][x + i + 1] = '>';
            }
        }
        // if alien, add tail
        else if (avatar == '@')
            grid[y][x + 1] = 'z';
    }
}

void View::display()
{
    int rows, cols, bounds;
    rows = grid.getRows();
    cols = grid.getCols();
    bounds = rows / 3;

    // top border
    cout << "|";
    for (int k = 0; k < cols; k++)
        cout << "-";
    cout << "|" << endl;

    // enter main area
    for (int i = 0; i < rows; i++)
    {
        // left wall
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
            // if blank, put a space
            if (grid[i][j] == 0)
                cout << " ";

            // else, print value along w/ color modifier
            cout << BOLD;
            switch (grid[i][j])
            {
            case 'T':
            case 'H':
            case '+':
                cout << WHITE;
                break;
            case 'D':
                cout << GREEN;
                break;
            case 'O':
            case '>':
                cout << YELLOW;
                break;
            case 'w':
                cout << CYAN;
                break;
            case '*':
                cout << MAGENTA;
                break;
            case '@':
            case 'z':
                cout << BLUE;
                break;
            default:
                cout << RED;
            }
            cout << grid[i][j] << RESET;
        }
        // if it's a cave
        if (i >= bounds && i < MAX_HEIGHT - bounds)
        {
            cout << "=";
            // add an emerald if it's the middle, else go to next line
            cout << BOLD << GREEN << ((i == MAX_HEIGHT / 2) ? " *" : "") << RESET << endl;
        }
        // else, regular wall
        else
        {
            cout << "|" << endl;
        }
    }

    // bottom border
    cout << "|";
    for (int k = 0; k < cols; k++)
        cout << "-";
    cout << "|" << endl;
}
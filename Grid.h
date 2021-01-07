#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
using namespace std;
#include <list>

#include "Player.h"
#include "constants.h"

/**CLASS: Grid<T>
 * A 2D array collection class template.
 * Base code provided by Christine Laurendeau
 *
 * ATTRIBUTES:
 * -rows: int
 * -cols: int
 * -data: T**
 *      Stores our inner 2D array
 *
 * METHODS:
 * +operator[](int): T*
 *      Overloaded [] operator to access rows of the grid
 * +refresh(): void
 *      Clears the grid
 */
template <class T>
class Grid
{
public:
    Grid(int = 10, int = 10);
    ~Grid();
    int getRows();
    int getCols();
    T *operator[](int);
    void refresh();

private:
    int rows;
    int cols;
    T **data;
};

// ------------------------ implementation ------------------------

template <class T>
Grid<T>::Grid(int r, int c) : rows(r), cols(c)
{
    // basic error checking
    if (r < 0 || c < 0)
    {
        cerr << "invalid capacity" << endl;
        exit(1);
    }
    // create the initial blank grid
    data = new T *[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new T[cols];
}

template <class T>
Grid<T>::~Grid()
{
    // delete each column first
    for (int i = 0; i < rows; i++)
        delete[] data[i];
    // delete each row
    delete[] data;
}

template <class T>
int Grid<T>::getRows() { return rows; }

template <class T>
int Grid<T>::getCols() { return cols; }

template <class T>
T *Grid<T>::operator[](int r)
{
    // basic error checking
    if (r < 0 || r >= rows)
    {
        cerr << "overflow" << endl;
        exit(1);
    }
    return data[r];
}

template <class T>
void Grid<T>::refresh()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // clear the grid
            data[i][j] = 0;
        }
    }
}

#endif
#ifndef CONSTANTS_H
#define CONSTANTS_H

// A header file to hold various constants

// hollow map size
const int MAX_WIDTH = 35;
const int MAX_HEIGHT = 7;

// delay between iterations (in milliseconds)
const int DELAY = 500;

// uncomment to clear the screen on each iteration
// #define REFRESH

// modifiers and colours for terminal output
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#endif
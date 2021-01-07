#include "Control.h"
#include <cstdlib>
#include <time.h>

/** MAIN
 *
 * PURPOSE:     Simulate a game of monsters and heroes.
 * USAGE:       Follow the console menu for user input. No command line arguments are required.
 * AUTHOR:      Vinh Nguyen
 * REVISIONS:   1.0
 */
int main()
{
    srand((unsigned)time(NULL));
    Control control;
    control.launch();
    return 0;
}

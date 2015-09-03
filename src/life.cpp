// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <iostream>
#include "grid.h"
#include "lifeutil.h"

int main() {

    // TODO: Finish the program!

    std::cout << "Welcome to the TDDD86 Game of Life," << std::endl
            << "a simulation of the lifecycle of a bacteria colony." << std::endl
            << "Cells (X) live and die by the following rules:" << std::endl
            << "- A cell with 1 or fewer neighbours dies." << std::endl
            << "- Locations with 2 neighbours remain stable." << std::endl
            << "- Locations with 3 neighbours will create life." << std::endl
            << "- A cell with 4 or more neighbours dies." << std::endl;
    return 0;
}

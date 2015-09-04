#include <iostream>
#include "grid.h"
#include "lifeutil.h"
#include <fstream>

using namespace std;

void getFile(ifstream& input,std::string filename){
    input.open(filename.c_str());

    if(!input.is_open()){
        std::cout << "Error madafacka" << std::endl;
    }
}


int main() {

    std::cout << "Welcome to the TDDD86 Game of Life," << std::endl
                << "a simulation of the lifecycle of a bacteria colony." << std::endl
                << "Cells (X) live and die by the following rules:" << std::endl
                << "- A cell with 1 or fewer neighbours dies." << std::endl
                << "- Locations with 2 neighbours remain stable." << std::endl
                << "- Locations with 3 neighbours will create life." << std::endl
                << "- A cell with 4 or more neighbours dies." << std::endl << std::endl;



    std::string filename;
    std::cout << "Please enter file name: " << std::endl;
    std::cin >> filename;

    ifstream stream;
    getFile(stream, filename);

    string line1;
    string line2;

    stream >> line1;
    stream >> line2;


      std::cout << line1 << std::endl;
      std::cout << line2 << std::endl;


    return 0;




}


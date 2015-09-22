#include <iostream>
#include "grid.h"
#include "lifeutil.h"
#include <fstream>

using namespace std;

void getFile(ifstream& input,std::string filename){
    input.open(filename.c_str());

    if(!input.is_open()){
        std::cout << "Error, input file not a present" << std::endl;
    }
}

void initiateGrid(Grid<char>& grid, ifstream& stream){
    std::string line;
    getline(stream, line);

    for (int row = 0; row < grid.numRows(); ++row) {
        getline(stream, line);
        for (int col = 0; col < grid.numCols(); ++col) {
            grid.set(row, col,  line[col]);
        }
    }
}


void printGrid(Grid<char>& grid) {
    int rows = grid.numRows();
    int cols = grid.numCols();
    string line;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            line += grid[row][col];
        }
        std::cout << line << std::endl;
        line = "";
    }
}

const char mSignAlive = 'X';
const char mSignDead = '-';

const char mSignAnimate = 'a';
const char mSignTick    = 't';
const char mSignQuit    = 'q';


bool calculateSurvival(Grid<char>& oldGen, int row, int col) {
    int nmAliveNeighbors = 0;

    for (int r = row - 1; r <= row + 1; ++r) {
        for (int c = col - 1; c <= col + 1; ++c) {
            if (oldGen.inBounds(r, c) && (c != col || r != row)) {
                if (oldGen[r][c] == mSignAlive) {
                    nmAliveNeighbors += 1;
                }
            }
        }
    }

    if(nmAliveNeighbors == 2){
        return oldGen[row][col] == mSignAlive;
    }

    return nmAliveNeighbors == 3;
}

void advanceGeneration(Grid<char>& oldGen) {
    int rows = oldGen.numRows();
    int cols = oldGen.numCols();
    Grid<char> newGen = Grid<char> (rows, cols);

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (calculateSurvival(oldGen, row, col)) {
                newGen.set(row, col, mSignAlive);
            } else {
                newGen.set(row, col, mSignDead);
            }
        }
    }
    oldGen = newGen;
}

void tick(Grid<char>& grid) {
    advanceGeneration(grid);
    pause(100);
    //clearConsole(); //Enable this if on a "clear screen" compatible machine
    }

int main() {

    std::cout << "Welcome to the TDDD86 Game of Life," << std::endl
                << "a simulation of the lifecycle of a bacteria colony." << std::endl
                << "Cells (X) live and die by the following rules:" << std::endl
                << "- A cell with 1 or fewer neighbours dies." << std::endl
                << "- Locations with 2 neighbours remain stable." << std::endl
                << "- Locations with 3 neighbours will create life." << std::endl
                << "- A cell with 4 or more neighbours dies." << std::endl;


    std::string filename;
    std::cout << "Please enter file name: " << std::endl;
    std::cin >> filename;

    ifstream stream;
    getFile(stream, filename);

    int rows;
    int cols;

    stream >> rows;
    stream >> cols;
    Grid<char> grid = Grid<char> (rows,cols);
    initiateGrid(grid,stream);

    char menuChoice;

    while (menuChoice != mSignQuit) {
        std::cout << "a)nimate, t)ick, q)uit?" << std::endl;
        printGrid(grid);
        std::cin >> menuChoice;

        switch(menuChoice){

        case mSignAnimate:
            while (true) {
                tick(grid);
                printGrid(grid);
            }
            break;

        case mSignTick:
            advanceGeneration(grid);
            break;

        }
    }

    std::cout << "Have a nice life!" << std::endl;
    return 0;
}



#include "ReelTable.hpp"
#include <iostream>

ReelTable::ReelTable() {

    // links all adjacent nodes to each other
    buildTable();


}

// links all neighbor nodes to each other and edges point to nullptr
void ReelTable::buildTable() {

    // initialize table
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            nodePtr newPtr = new ReelNode();
            table[i][j] = newPtr;      
        }
    }

    // link table
    for(int i = 0; i < width; i++) {

        for(int j = 0; j < height; j++) {

            // node does not exist on bottom row
            if(j != 2) {
                table[i][j]->down = table[i][j + 1];
            }

            // node does not exist on top row
            if(j != 0) {
                table[i][j]->up= table[i][j - 1];
            }

            // node does not exist on right column
            if(i != 4) {
                table[i][j]->right = table[i][j + 1];
            }

            // node does not exist on left column
            if(i != 0) {
                table[i][j]->left= table[i][j - 1];
            }

        }
    }
}

void ReelTable::printTable() {
    

    for(int j = 0; j < height; j++) {
        for(int i = 0; i < width; i++) {

            std::cout << static_cast<int>(table[i][j]->item) << " ";


        }

        std::cout << "\n";
    }

}

#include "MachineFunds.hpp"

// constructor
MachineFunds::MachineFunds() :
    filename_{"data.dat"}
    {

    }


// Saves slot balance to memory (EEPROM on embedded system) after each balance change.
// Balance needs to exist in permanent storage in the case of a machine crash or restart.
int MachineFunds::saveBalanceToMemory() {

    // when overwritting, we need to truncate previous file 
    std::ofstream outputFile(filename_, std::ios::trunc);

    // opens output file
    if (outputFile) {
        outputFile << balance_; // loads balance into output file
        outputFile.flush();  // ensures data is written to disk immediately
        outputFile.close(); // closes file
        return 0;
    }

    // error opening
    else {
        std::cerr << "Error! Cannot open output file.\n";
        return 1;
    }

}

int MachineFunds::loadBalanceFromMemory() {

    std::ifstream inputFile(filename_);

    if (inputFile) {
        int value;
        inputFile >> value;
        balance_ = static_cast<Balance>(value); // casts value to uint32_t
        return 0;

    } else {
        std::cerr << "Error! Cannot open input file .\n";
        return 1;
    }

}

int MachineFunds::getBalance() const {
    return balance_;
}

int MachineFunds::getCredits() const {
    return credits_;
}
    

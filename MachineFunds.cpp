
#include "MachineFunds.hpp"

// constructor
MachineFunds::MachineFunds() :
    filename_{"data.dat"},
    denomination_{Denomination::QuarterDollar}
    {
        // only required on boot
        if(loadBalanceFromMemory() == 0) {
            std::cout << "Succesfully recovered funds!\n";
        }
        else {
            system("pause");
        }

    }


void MachineFunds::changeDenom(Denomination denomination) {
    
    denomination_ = denomination;

    // C++ rounds down, the switch cases give 25, 50, and 100 cent credit values respectively 
    switch (static_cast<int>(denomination_)) {
        case 0:
            credits_ = balance_/25;
            break;
        case 1:
            credits_ = balance_/50;
            break;
        case 2:
            credits_ = balance_/100;
            break;
        default:
            std::cerr << "Error! Invalid denomination value\n";
    }

}


Balance MachineFunds::getBalance() const {
    return balance_;
}


Credits MachineFunds::getCredits() const {
    return credits_;
}

Denomination MachineFunds::getDenomination() const {
    return denomination_;
}


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
    

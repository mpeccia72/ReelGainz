
#include "MachineFunds.hpp"

// constructor
MachineFunds::MachineFunds() :
    filename_{"data.dat"},
    creditDenomination_{CreditDenomination::QUARTER_DOLLAR}
    {
        // only required on boot
        if(loadBalanceFromMemory() == 0) {
            std::cout << "Succesfully recovered funds!\n";
        }
        else {
            system("pause");
        }

    }


void MachineFunds::changeDenom(CreditDenomination creditDenomination) {
    
    creditDenomination_ = creditDenomination;

    // C++ rounds down, the switch cases give 25, 50, and 100 cent credit values respectively 
    switch (static_cast<int>(creditDenomination_)) {
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
            std::cerr << "Error! Invalid credit denomination value\n";
    }

}


bool MachineFunds::deductCredits(Credits credits) {

    // checks if transcation will go through and returns true if so
    if(credits_ - credits > -1) {
        credits_ -= credits;
        return true;
    }
    else {
        return false;
    }

}


void MachineFunds::addFunds(BillDenomination billDenomination) {

    // User inserts a $x bill, x dollars are added to balance 
    switch (static_cast<int>(billDenomination)) {
        case 0:
            balance_ += 100;
            break;
        case 1:
            balance_ += 500;
            break;
        case 2:
            balance_ += 1000;
            break;
        case 3:
            balance_ += 2000;
            break;
        case 4:
            balance_ += 5000;
            break;
        case 5:
            balance_ += 10000;
            break;
        default:
            std::cerr << "Error! Invalid bill denomination value\n";
    }

    saveBalanceToMemory(); // saves balance to permament memory 
    changeDenom(creditDenomination_); // updates machine credits to reflect new balance

} 


Money MachineFunds::getBalance() const {
    return balance_;
}


Credits MachineFunds::getCredits() const {
    return credits_;
}


CreditDenomination MachineFunds::getCreditDenomination() const {
    return creditDenomination_;
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
        balance_ = static_cast<Money>(value); // casts value to uint32_t
        return 0;

    } else {
        std::cerr << "Error! Cannot open input file .\n";
        return 1;
    }

}
    

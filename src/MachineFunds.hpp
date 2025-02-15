
#include <cstdint>
#include <fstream>
#include <iostream>

using Credits = uint32_t;
using Money  = uint32_t; // US Dollars (penny-based)

// credit denomination
enum class CreditDenomination{
    QUARTER_DOLLAR,
    HALF_DOLLAR,
    DOLLAR
};

// bill denominations accepted
enum class BillDenomination {
    SINGLE,
    FIVE,
    TEN,
    TWENTY,
    FIFTY,
    HUNDRED
};


// This class handles the clearing of machine funds.
class MachineFunds {

    public:

        MachineFunds(); // constrcutor

        // Public API
        void changeDenom(CreditDenomination); // updates denomination
        bool deductCredits(Credits); // deducts credits
        void addFunds(BillDenomination); // adds money to balance
        Credits getCredits() const;
        Money getBalance() const;
        CreditDenomination getCreditDenomination() const;


    private:
        Money balance_;
        Credits credits_;
        CreditDenomination creditDenomination_;
        std::string filename_;
        
        
        // In case of system crash or restart, the balance needs to be stored in permament storage 
        int saveBalanceToMemory(); // Saves slot balance to memory (EEPROM on embedded system) after each balance change.
        int loadBalanceFromMemory(); // Loads slot balance from memory (EEPROM on embedded system), typically after restarts or boots

};
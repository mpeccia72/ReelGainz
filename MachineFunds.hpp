
#include <cstdint>
#include <fstream>
#include <iostream>

using Credits = uint32_t;
using Balance  = uint32_t; // US Dollars (penny-based)

// credit denomination
enum class Denomination{
    QuarterDollar,
    HalfDollar,
    Dollar
};


// This class handles the clearing of machine funds.
class MachineFunds {

    public:

        MachineFunds(); // constrcutor

        // Public API
        void changeDenom(Denomination); // updates denomination
        Credits getCredits() const;
        Balance getBalance() const;
        Denomination getDenomination() const;


    private:
        Balance balance_;
        Credits credits_;
        Denomination denomination_;
        std::string filename_;
        
        
        // In case of system crash or restart, the balance needs to be stored in permament storage 
        int saveBalanceToMemory(); // Saves slot balance to memory (EEPROM on embedded system) after each balance change.
        int loadBalanceFromMemory(); // Loads slot balance from memory (EEPROM on embedded system), typically after restarts or boots

};
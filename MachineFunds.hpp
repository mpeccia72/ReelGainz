
#include <cstdint>
#include <fstream>
#include <iostream>

using Credits = uint32_t;
using Balance  = uint32_t; // US Dollars


class MachineFunds {


    public:

        MachineFunds();

        void changeDenom(int); // changes de

        




        // getters
        int getCredits() const;
        int getBalance() const;


    private:
        Balance balance_;
        Credits credits_;
        std::string filename_;
        
        
        // In case of system crash or restart, the balance needs to be stored in permament storage 
        int saveBalanceToMemory(); // Saves slot balance to memory (EEPROM on embedded system) after each balance change.
        int loadBalanceFromMemory(); // Loads slot balance from memory (EEPROM on embedded system), typically after restarts or boots

};

/*
    Testing file for MachineFunds
*/

#include <iostream>
#include "MachineFunds.hpp"

int main() {

    MachineFunds funds;

    while(true) {
        auto bal = funds.getBalance();
        auto cd = static_cast<int>(funds.getCreditDenomination());
        auto credits = funds.getCredits();

        std::cout << "\n"
                  << "Balance: " << bal << "\n"
                  << "Credit Denomination: " << cd << "\n"
                  << "Credits: " << credits << "\n\n";
        
        std::cout << "1) Add money 2) Deduct Credits 3) Change Credit Denomination\n";
        takeback:

        int input;
        std::cin >> input;

        switch(input) {
            case 1:
                std::cout << "0) SINGLE 1) FIVE 2) TEN 3) TWENTY 4) FIFTY 5) HUNDRED\n";
                std::cin >> input;
                funds.addFunds(static_cast<BillDenomination>(input));
                break;
            case 2:
                std::cout << "Enter amount to deduct: \n";
                std::cin >> input;
                funds.deductCredits(input);
                break;
            case 3:
                std::cout << "0) $0.25 1) $0.50 2) $1.00\n";
                std::cin >> input;
                funds.changeDenom(static_cast<CreditDenomination>(input));
                break;
            default:
                std::cout << "Choose 1 - 3 please!\n";
                goto takeback;
                break;

        }        

    }

    return 1;

}
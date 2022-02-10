/**
 *   @file: atm.cc
 * @author: KaraBeth Nemet
 *   @date: February 2 2022 (2/2/22)
 *  @brief: Add program Description
 */

#include <iomanip>
#include <iostream>
using namespace std;

/// Constants and function prototypes
// double BALANCE = 1000.00;

int main(int argc, char const *argv[])
{

    int pinnumber;
    double balance = 1000;
    double withdrawamount;
    double currentaccountvalue;
    char transactionquestion;
    bool anothertransaction = true;
    int pintries = 0;

    cout << fixed << setprecision(2);
    cout << "Welcome to Bobcats Bank ATM Machine" << endl;
    do
    {
        cout << "Pin : ";
        cin >> pinnumber;

        while (pinnumber != 1234)
        {
            ++pintries;
            cout << "WRONG PIN, you have " << 3 - pintries << " tries left. Please try again : ";
            cin >> pinnumber;
            if (pintries > 1)
            {
                cout << "WRONG PIN, too many tries, your account has been locked";
                return (0);
            }
        }

        while (pinnumber == 1234 && anothertransaction == true)
        {
            cout << "Enter the amount you wish to withdraw: $";
            cin >> withdrawamount;

            if (withdrawamount > balance)
            {
                do
                {
                    cout << "You do not have the funds. Please try again." << endl;
                    cout << "Enter the amount you wish to withdraw: $";
                    cin >> withdrawamount;
                } while (withdrawamount > balance);
            }
            currentaccountvalue = balance - withdrawamount;
            balance = currentaccountvalue;
            cout << "Your current balance is $" << currentaccountvalue << endl;
            break;
        }

        cout << "Another Transaction (y/n)? ";
        cin >> transactionquestion;
        if (transactionquestion != 'y')
        {
            anothertransaction = false;
        }

    } while (anothertransaction == true);

    cout << "Have a nice day :)" << endl;
}

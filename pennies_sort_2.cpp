#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
     /**
     * PURPOSE: this program takes inputs from the user in measures of
     * half-dollar, quarters, dimes, nickels, and pennies.
     * Then outputs the total amount of pennies and USD amount.
     */

     // declare variables
     int halfDollars = 0;
     int quarters = 0;
     int dimes = 0;
     int nickels = 0;
     int pennies = 0;
     int penniesTotal = 0;
     int coinsTotal = 0;
     double usDollars = 0;

     // store inputs from user
     cout << "Enter half dollars: " << endl;
     cin >> halfDollars;
     coinsTotal += halfDollars;
     penniesTotal = halfDollars * 50;

     cout << "Enter quarters: " << endl;
     cin >> quarters;
     coinsTotal += quarters;
     penniesTotal += quarters * 25;

     cout << "Enter dimes: " << endl;
     cin >> dimes;
     coinsTotal += dimes;
     penniesTotal += dimes * 10;

     cout << "Enter nickels: " << endl;
     cin >> nickels;
     coinsTotal += nickels;
     penniesTotal += nickels * 5;

     cout << "Enter pennies: " << endl;
     cin >> pennies;
     coinsTotal += pennies;
     penniesTotal += pennies;

     // convert pennies amount to dollar format
     usDollars = penniesTotal;
     usDollars = usDollars / 100;

     cout << "The value of your " << coinsTotal << " coins is equivalent to " << penniesTotal << " pennies, or $" << std::fixed << setprecision(2) << usDollars << endl;

     return 0;
}

/*
Enter half dollars:
1
Enter quarters:
2
Enter dimes:
3
Enter nickels:
4
Enter pennies:
5
The value of your 15 coins is equivalent to 155 pennies, or $1.55
*/

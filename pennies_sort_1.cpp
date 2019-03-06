#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

string breakCash(int numPennies)
{
/**
 * FUNCTION NAME: breakCash
 * PURPOSE: the function takes in the total of pennies from the user as input, computes its equivalent in
 * dollars, quarters, dimes, nickels, and pennies, and outputs the result in string to the console
 * PARAMETER:
 *     int numPennies
 * RETURN VALUE:
 *     string: result in dollars, quarters, dimes, nickels, and pennies
 * FUNCTION SINGATURE:
 * string breakCash(int numPennies)
 */
    // calculate Canadian dollar amount
    float canadianTotal = numPennies * .0133;

    // split total amount of pennies into dollars, quarters, nickels, dimes, and pennies

    int dollars = numPennies / 100;
    numPennies = numPennies % 100;

    int quarters = numPennies / 25;
    numPennies = numPennies % 25;

    int dimes = numPennies / 10;
    numPennies = numPennies % 10;

    int nickels = numPennies / 5;
    numPennies = numPennies % 5;

    int pennies = numPennies;

    // display results
    std::stringstream ss;
    ss << "In US currency you have: " << dollars << " dollars, " << quarters << " quarters, " << dimes << " dimes, "
        << nickels << " nickels, and " << pennies << " pennies." << endl << "In Canadian currency you have: $"
        << std::fixed << setprecision(2) << canadianTotal << endl;
    return ss.str();
}

int main()
{
  int numOfPennies = 0;
  // retrieve amount of pennies from user
  cout << "Enter all of your pennies:" << endl;
  cin >> numOfPennies;
  cout << breakCash(numOfPennies);
  return 0;
}

/*
Enter all of your pennies:
149
In US currency you have: 1 dollars, 1 quarters, 2 dimes, 0 nickels, and 4 pennies.
In Canadian currency you have: $1.98
*/

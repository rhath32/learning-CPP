#include <iostream>
#include <string>
using namespace std;

/**
 * FUNCTION NAME: separateLetters
 * PURPOSE: the function takes an input string consisting of a's and b's and sorts the them alphabetically,
 * then returns the result as a new string
 * PARAMETER:
 *     string input
 * RETURN VALUE:
 *     string: result of inputted a and b characters sorted
 * FUNCTION SINGATURE:
 * string separateLetters(string input)
 */
string separateLetters(string input)
{
    // Declare variables
    string aString;
    string bString;
    string newString;

    // Loop through input string and sort into aString and bString
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'a')
            aString += 'a';
        else
            bString += 'b';
    }

    // Concatenate aString and bString then store into newString
    newString = aString + bString;
    return newString;
}
int main()
{
    // Prompt user for input and pass input into separateLetters
    string input;
    cout << "Enter a string consisting of a's and b's: " << endl;
    cin >> input;
    cout << "Output: " << separateLetters(input);

    return 0;
}

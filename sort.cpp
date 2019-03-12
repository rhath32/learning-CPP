#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> inputs;
    int input = 0;
    int smallest = 0;
    int largest = 0;
    int sum = 0;

    cout << "Enter integer inputs and watch as the program outputs either the smallest or largest values."
        << endl << "To end the game and view the list of all inputs as well as the sum, enter a non valid character" << endl;

    while (cin >> input)
    {
        if (inputs.size() == 0) // If this is first input, store in smallest and largest
        {
            smallest = input;
            largest = input;
            cout << input << " is the first input." << endl;
        }
        else if (input < smallest)
        {
            smallest = input;
            cout << smallest << " is the smallest value." << endl;
        }
        else if (input > largest)
        {
            largest = input;
            cout << largest << " is the largest value." << endl;
        }
        else
            cout << input << endl;

        inputs.push_back(input); // add current input to back of vector
        sum += input; // add current input to total sum of inputs
    }
}

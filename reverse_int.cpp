#include <iostream>

class CIS14 
{
	public:
		int reverseInt(int input);
};

int main()
{
	// instantiate an instance of CIS14 class
	CIS14 cis14;

	// invoke this instance's member function one  by one
	std::cout << cis14.reverseInt(14) << "\n";
	std::cout << cis14.reverseInt(-123) << "\n";
	std::cout << cis14.reverseInt(1000) << "\n";
	std::cout << cis14.reverseInt(10) << "\n";
	std::cout << cis14.reverseInt(-14) << "\n";
	std::cout << cis14.reverseInt(1000000119);
	return 0;
}

/**
* FUNCTION SIGNATURE: int reverseInt(int input)
* PURPOSE: reverse the integer provided
* PARAMETER:
*     int input, input integer to be reversed
* RETURN VALUE:
*     reversed integer
*/
int CIS14::reverseInt(int input)
{
	int n = input, rem = 0, reversedInt = 0, overflowTest = 0;

	while (n != 0)
	{
		rem = n % 10; 
		reversedInt = reversedInt * 10 + rem; 

		// check if reversed number overflowed
		if ((reversedInt - rem) / 10 != overflowTest)
			return 0;

		overflowTest = reversedInt;
		n /= 10;
	}
	return reversedInt;
}

/** SAMPLE OUTPUTS
INPUT: 14
OUTPUT: 41

INPUT: -14
OUTPUT: -41

INPUT: 01
OUTPUT: 1

INPUT: 1000000119
OUTPUT: 0
*/


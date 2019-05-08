#include <iostream>

int convertString2Integer(std::string str);

int main()
{
	std::cout << convertString2Integer("123") << "\n";
	std::cout << convertString2Integer("-123") << "\n";
	std::cout << convertString2Integer("0000012") << "\n";
	std::cout << convertString2Integer("-999") << "\n";
	std::cout << convertString2Integer("000000000000000123") << "\n";
	return 0;
}

/**
* FUNCTION SIGNATURE: int converString2Integer(std::string str)
 * PURPOSE: converts string to an integer
 * PARAMETER:
 *     std::string str, input string to be converted
 * RETURN VALUE:
 *     integer equivalent of string
*/
int convertString2Integer(std::string str)
{
	int intReturn = 0;
	bool negNum = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '-') // check if negative number
		{
			i++;
			negNum = 1;
		}
		intReturn = intReturn * 10 + (str[i] - '0');
	}

	if (negNum == 1) // convert int to negative
		intReturn *= -1;
	return intReturn;
}

/** SAMPLE OUTPUT
INPUT: "123"
OUTPUT: 123

INPUT: "-123"
OUTPUT: 123

INPUT: "000000000123"
OUTPUT: 123
*/

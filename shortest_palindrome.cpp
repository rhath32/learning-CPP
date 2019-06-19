/*
--LOGIC ERRORS--
input: 19999
expected: 7
my output: 9

input: 1010100
expected: 12
my output: 1

input: 10101001
expected: 12
my output: 1
*/


#include <iostream>

/**
 * FUNCTION NAME: isNumPalindrome
 * PURPOSE:
 *     receives integer n and returns boolean value if n is palidrome or not.
 * PARAMETER:
 *     integer n
 * RETURN VALUE:
 *     bool, if n is palindrome return 1, if not return 0.
 * FUNCTION SINGATURE:
 *     int getShortestLength(int n)
 */
bool isNumPalindrome(int n)
{
	int digit = 0, reversedNum = 0, num = n;

	if (n < 10)
	{
		if (n < 0) // neg numbers cannot be palindrome
			return false;
		else // single digit positive numbers are palindome
			return true;
	}

	else
	{
		// reverse num
		do
		{
			digit = num % 10;
			reversedNum = (reversedNum * 10) + digit;
			num = num / 10;
		} while (num != 0);

		if (reversedNum == n) // check if n reversed == n. if so, n is palindrome
			return true;
		else
			return false;
	}

}
/**
 * FUNCTION NAME: getShortestLength()
 * PURPOSE:
 *     to check if input is a palindrome. If it is, return the smallest possible palindrome size.
 * PARAMETER:
 *     integer n
 * RETURN VALUE:
 *     integer: size of the smallest possible palindrome
 * FUNCTION SINGATURE:
 *     int getShortestLength(int n)
 */
int getShortestLength(int n)
{
	int num = n, digits = 0;

	// check if palindrome
	if (isNumPalindrome(n) == true)
	{
		// count digits
		do
		{
			digits++;
			num = num / 10;
		} while (num != 0);
		return digits;
	}

	else // append first digit onto end of number and retest
	{
		int lastDigit = 0;
		
		do
		{
			num = num / 10; 
			lastDigit = num % 10; 
			n = (n * 10) + lastDigit; 
		} while (isNumPalindrome(n) == false);

		return getShortestLength(n);
	}
}

int main()
{
	int input = 0;
	std::cout << "Enter a number: \n";
	std::cin >> input;
	std::cout << "Shortest possible palindrome: " << getShortestLength(input);
	return 0;
}

/* Sample Outputs
Enter a number:
12345
Shortest possible palindrome: 9

Enter a number:
-131
Shortest possible palindrome: 0

Enter a number:
0
Shortest possible palindrome: 0

Enter a number:
131
Shortest possible palindrome: 3
*/

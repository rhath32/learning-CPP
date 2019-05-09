// DYNAMIC PROGRAMMING 
#include<iostream>

int getLargestConsecutiveSum(const int[], int);

int main() 
{
	int int_array[] = { 1, -3, 23, 4, 9, 2, 29, -3, 0, 2, 48, 7, 6, -1 };
	std::cout << "Largest Consecutive Sum: " << getLargestConsecutiveSum(int_array, sizeof(int_array) / sizeof(*int_array));
	return 0;
}

/**
 * FUNCTION NAME: getLargestConsecutiveSum
 * PURPOSE:
 *     receive an input array of integers, and return to the maximum possible sum of consecutive integers
 * PARAMETER:
 *     const int arr[], array of integers
 *	   int length, length of input array
 * RETURN VALUE:
 *    int finalMax, integer of maximum possible sum 
 * FUNCTION SINGATURE:
 *     int getLargestConsecutiveSum(const int arr[], int length) 
 */
int getLargestConsecutiveSum(const int arr[], int length) 
{
	int currentMax = 0, finalMax = 0;

	for (int i = 0; i < length; i++)
	{
		currentMax += arr[i];

		if (finalMax < currentMax)
			finalMax = currentMax;

		if (currentMax < 0)
			currentMax = 0;
	}
	return finalMax;
}

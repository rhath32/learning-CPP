/** This is a simple example of a Kadane's dynamic programming algorithm.
*   This algorithm iterates through the array and looks for all POSITIVE contigous segments.
*   For each positive contigous segment, we keep track of the sum of the segment.
*   Each time we get a positive sum, compare it to previous positive MAX sum. 
*   If it is larger than previous positive MAX sum, set as new MAX sum.
*/
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
	int currentSum = 0, finalSum = 0;

	for (int i = 0; i < length; i++) // loop through array
	{
		currentSum += arr[i]; // add current element to currentMAx

		if (finalSum < currentSum) // if currentSum is larger than finalSum
			finalSum = currentSum; // set currentSum to finalSum

		if (currentSum < 0) // if currentSum is negative, set to 0
			currentSum = 0;
	}
	return finalSum;
}

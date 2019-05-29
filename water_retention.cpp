/* This code takes input array of various elevation heights and calculate water retention given the terrain
*/

#include <iostream>

int getTotalWaterAmount(int* arr, int size);

int main()
{
	int terrain[4] = { 5,4,1,2 };
	int size = sizeof(terrain) / sizeof(terrain[0]);

	std::cout << getTotalWaterAmount(terrain, size);
	return 0;
}

/**
* FUNCTION SIGNATURE: getTotalWaterAmount(int* arr, int size)
 * PURPOSE: calculates amount of water retention given array of terrain elevation heights
 * PARAMETER:
 *     int* arr, pointer to array of terrain
 *	   int size, size of array
 * RETURN VALUE:
 *     integer, total amount of water retained
*/
int getTotalWaterAmount(int* arr, int size)
{
	int waterRetention = 0, peakPos = 0, globalMax = arr[0], leftMax = 0, rightMax = 0,
		left = 0, right = size - 1;

	// find global max
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > globalMax)
		{
			globalMax = arr[i];
			peakPos = i;
		}
	}
	// 2 pointers from left and right to collect water
	for (int i = 0, j = size - 1; i < peakPos; i++)
	{
		if (arr[i] > leftMax) // update left max
			leftMax = arr[i];
		else
			waterRetention += (leftMax - arr[i]); // add water
	}
	for (int j = size - 1; j > peakPos; j--)
	{
		if (arr[j] > rightMax) // update right max
			rightMax = arr[j];
		else
			waterRetention += (rightMax - arr[j]); // add water
	}
	return waterRetention;
}

/* ---SAMPLE OUTPUTS
INPUT:  {5,2,1,2,1,5}
OUTPUT: 14

INPUT: {10, 20, 30 , 40, 42, 40, 30, 20, 40, 50, 55, 50, 40, 30, 20, 10, 3}
OUTPUT: 38

INPUT: {0,1,2,5,4,2,6,4,3,2,1,1,1,1,1,1,8}
OUTPUT: 43
*/

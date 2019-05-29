/* This code takes an array of "pockets". Each integer is a hole in the ground.
*  The function is to find the largest possible area that can be cut out of the ground
*  to store the most water.
 */

#include <iostream>

int getMaxPond(int* arr, int size);

int main()
{
	int pond[12] = { 0, 5, 3, 1, 2, 0, 4, 6, 9, 0, 0, 0 };
	int arraySize = sizeof(pond) / sizeof(pond[0]);

	std::cout << getMaxPond(pond, arraySize);
	return 0;
}

/**
* FUNCTION SIGNATURE: int getMaxPond(int* arr, int size)
 * PURPOSE: takes array input of elevation profile and outputs maximum cross sectional
 *		    area of water retention
 * PARAMETER:
 *     int* arr, pointer to array of terrain
 *	   int size, size of array
 * RETURN VALUE:
 *     integer, total amount of water retained
*/
int getMaxPond(int* arr, int size)
{
	int count = 0, max = 0, atLeastOne = 0;

	if (size < 2)
		return 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= 1 && arr[i + 1] >= 1)
			atLeastOne++;
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j] >= arr[i])
			{
				count = j - i;
				if (count * arr[i] > max)
					max = count * arr[i];
				break;
			}
		}
	}
	if (max > atLeastOne)
		return max;
	else
		return atLeastOne;
}

/* ---SAMPLE OUTPUTS
INPUT: { 0, 5, 3, 1, 2, 0, 4, 6, 9, 0, 0, 0 }
OUTPUT: 35

INPUT: { 1, 2, 3, 1, 2, 1, 4, 8, 2, 2, 2, 0 }
OUTPUT: 18

INPUT: {1,99,1}
OUTPUT: 2
*/

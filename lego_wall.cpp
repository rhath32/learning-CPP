// This commit is heavily commented to help me further understand(and remember) the basics of dynamic programming. 

#include <iostream>
#include <vector>

int getLegoCombinations(std::vector<int> &lego_heights, int target_height);

int main()
{
	std::vector<int> lego_heights = { 1,2,5 }; // create vector of lego blocks with various heights
	int target_height = 7; // target sum
	std::cout << "Total Combinations: " << getLegoCombinations(lego_heights, target_height); // pass the vector and target height into function
	return 0;
}

/**
* FUNCTION SIGNATURE: int getLegoCombinations(std::vector<int> &lego_heights, int target_height)
 * PURPOSE: output maximum number of ways to to use lego bricks with varying heights to equal target height
 * PARAMETER:
 *     std::vector<int> &lego_heights, various lego brick heights
	   int target_height, the target combined height
 * RETURN VALUE:
 *     number of combinations
 */
int getLegoCombinations(std::vector<int> &lego_heights, int target_height)
{
	// vector to store solutions
	// size = target_height + 1 to prevent overflow
	// initialize all values to 0
	// set first element to = 1
	std::vector<int> solutions(target_height + 1, 0); 
	solutions[0] = 1; 

	// edge case
	// if the height is 0, unable to solve
	if (target_height == 0)
		return 0;
	else
	{
		// iterate through lego heights {1,2,5}
		for (int i = 0; i < lego_heights.size(); i++)
		{
			// iterate through solutions indexes {1,0,0,0,0,0,0,0}
			// compare each index value of solutions with the heights value
			// i = height, j = solution index
			for (int j = 0; j < solutions.size(); j++)
			{
				if (lego_heights[i] <= j) // if height value is <= solutions index
					solutions[j] += solutions[j - lego_heights[i]]; // add value of solutions[j - height] index to current
			}
		}
		return solutions[target_height];
	}
}

/* --SAMPLE OUTPUT--
INPUT: { 1,2,5 }, 7
OUTPUT: Total Combinations: 6

INPUT: { 1,2,5 }, 0
OUTPUT: Total Combinations: 0

INPUT: { 5 }, 9
OUTPUT: 0
*/

/*
Lego heights {1,2,5}
Solutions beginning {1,0,0,0,0,0,0,0}
{1,1,1,1,1,1,1,1} lego height 1
{1,1,2,2,3,3,4,4} lego height 2
{1,1,2,2,3,4,5,6} lego height 5. Solution is the final element
*/

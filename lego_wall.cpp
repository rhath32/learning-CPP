#include <iostream>
#include <vector>

int getLegoCombinations(std::vector<int> &lego_heights, int target_height);

int main()
{
	std::vector<int> lego_heights = { 5 };
	int target_height = 6;
	std::cout << "Total Combinations: " << getLegoCombinations(lego_heights, target_height);
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
	std::vector<int> solutions(target_height + 1, 0);
	solutions[0] = 1; 

	if (target_height == 0)
		return 0;
	else
	{
		// iterate through lego heights
		for (int i = 0; i < lego_heights.size(); i++)
		{
			// iterate through solutions indexes
			// compare each index value of solutions with the heights value
			for (int j = 0; j < solutions.size(); j++)
			{
				if (lego_heights[i] <= j)
					solutions[j] += solutions[j - lego_heights[i]];
			}
		}
		return solutions[target_height];
	}
}

/* --SAMPLE OUTPUT--

*/

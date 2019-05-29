#include <iostream>
#include <vector>

class MaxPoints
{
	public:
		int getMaxPoints(std::vector<std::vector<int>> &maze);
};

int main()
{
	std::vector<std::vector<int>> maze = { {2}, {4,1}, {5,3,8}, {1,6,7,3} };
	MaxPoints maxPoints;

	std::cout << maxPoints.getMaxPoints(maze);
	return 0;
}

/**
* FUNCTION SIGNATURE: getMaxPoints(std::vector<std::vector<int>> &maze)
 * PURPOSE: finds highest sum path in "pyramid" of arrays
 * PARAMETER:
 *     vector<vector<int>> &maze, 
 *			reference to vector of vectors
 * RETURN VALUE:
 *			integer value of highest possible sum
*/
int MaxPoints::getMaxPoints(std::vector<std::vector<int>> &maze)
{
	if (maze.empty())
		return 0;

	std::vector<std::vector<int>> mazeSum = maze;

	for (int i = mazeSum.size() - 2; i > -1; i--) // iterate through vector of vectors
	{
		if ((mazeSum[i].empty()) || (mazeSum[i + 1].empty()))
			return 0;

		// iterate through each element in current inner vector
		// compare inner vector elements and add highest to previous vector
		// total sum ends up at top of "pyramid" [0][0]
		for (int j = 0; j < mazeSum[i].size(); j++) 
		{
			if (mazeSum[i + 1][j] > mazeSum[i + 1][j + 1])
				mazeSum[i][j] += mazeSum[i + 1][j];
			else
				mazeSum[i][j] += mazeSum[i + 1][j + 1];
		}
	}
	return mazeSum[0][0];
}

/* ---SAMPLE OUTPUT---
INPUT: { {2}, {4,1}, {5,3,8}, {1,6,7,3} }
OUTPUT: 18

INPUT: {{1}, {1,22305}, {1,29394,1}, {1,1,1234,1}, {1,1,3,1,10}}
OUTPUT: 52937
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> getMaxHits(std::vector<int> &requests, int window_size); 

int main()
{
	std::vector<int> requests = {1,2,3,4,5,6,7,8,9,10};
	int window_size = 3;
	std::vector<int> maxValues = getMaxHits(requests, window_size);

	//display results
	std::cout << "{"; 
	for (int i = 0; i < maxValues.size(); i++)
	{
		if (i < maxValues.size() - 1)
			std::cout << maxValues[i] << ",";
		else
			std::cout << maxValues[i];
	}
	std::cout<< "}";
	return 0;
}

/**
* FUNCTION SIGNATURE: std::vector<int> getMaxHits(std::vector<int> &requests, int window_size)
 * PURPOSE: find the max hits at every rolling window of specific length that moves with time
 * PARAMETER:
 *     std::vector<int> &requests, input vector of requests
	   int window_size, rolling window length
 * RETURN VALUE:
 *     vector of max values
*/


std::vector<int> getMaxHits(std::vector<int> &requests, int window_size) 
{
	std::vector<int> maxValues = {}; 
	std::vector<int> temp = {};

	if ((window_size <= 0) || (window_size > requests.size())) // edge cases
		return maxValues;
	else
	{
		for (int i = 0; i < requests.size(); i++) // outer loop to iterate through each element 1 at a time
		{
			for (int j = i; j < (i + window_size); j++) // store elements in 'window' into temp vector
			{
				if ((i + window_size) > requests.size())
					break; // inner
				else
					temp.push_back(requests[j]);
			}

			if ((i + window_size) > requests.size())
				break; // outer
			else
			{
				maxValues.push_back(*std::max_element(temp.begin(), temp.end())); // add highest element from temp window to maxValues stack
				temp.clear();
			}
		}
		return maxValues;
	}
}

/* --SAMPLE OUTPUT--
input: {4,4,4,3,5,2,1}, 3
output: {4,4,5,5,5}

input: {1,2,3,4,5,6,7,11,8,9,10}, 4
output: {4,5,6,7,11,11,11,11}

input: {0,0,0}, 3
output: {0}

input: {0,0,0}, 4
output: {}
*/

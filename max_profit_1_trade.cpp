#include <iostream>
#include <vector>
#include <algorithm>

int getMaxProfit(std::vector<int> &prices);

int main()
{
    std::vector<int> prices = {3,1,5,2,4};
    std::cout << "Max profit: " << getMaxProfit(prices);
    return 0;
}

/**
* FUNCTION SIGNATURE: int getMaxProfit(std::vector<int> &prices)
 * PURPOSE: find the maximum available profit possible from a vector of stock prices
 *          using only ONE trade, the most profitable one
 * PARAMETER:
 *     std::vector<int> &prices, vector of stock prices
 * RETURN VALUE:
 *     maximum profit possible
*/
int getMaxProfit(std::vector<int> &prices)
{
    int highIndex = std::max_element(prices.begin(), prices.end()) - prices.begin();
    double high = *max_element(prices.begin(), prices.end());
    int lowIndex = std::min_element(prices.begin(), prices.begin() + highIndex) - prices.begin();
    double low = *min_element(prices.begin(), prices.begin() + highIndex);
    int profit = high - low;

    if ((prices.size() == 1) || (highIndex < lowIndex))
        return 0;
    else
        return profit;
}

/* --SAMPLE OUTPUT--
INPUT: {2,3,4,5,6,1}
OUTPUT: 4

INPUT: {1,2,5,1,6}
OUTPUT: 5
*/



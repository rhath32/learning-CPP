#include <iostream>
#include <vector>

int getMaxProfit(std::vector<int> &prices);

int main()
{
    std::vector<int> prices = {3,4};
    std::cout << "Maximum profit: " << getMaxProfit(prices);
    return 0;
}

/**
* FUNCTION SIGNATURE: int getMaxProfit(std::vector<int> &prices)
 * PURPOSE: find the maximum available profit possible from a vector of stock prices
 *          using MULTIPLE trades
 * PARAMETER:
 *     std::vector<int> &prices, vector of stock prices
 * RETURN VALUE:
 *     maximum profit possible
*/
int getMaxProfit(std::vector<int> &prices)
{
    int profit = 0;

    for(int i = 0; i < prices.size(); i++)
    {
        if (prices[i + 1] > prices[i])
            profit += prices[i + 1] - prices[i];
    }

    return profit;
}

/* --SAMPLE OUTPUT--
INPUT: {1,3,4,3,1,7}
OUTPUT: 9

INPUT: {1,2,4}
OUTPUT: 3

INPUT: {1,2,5,1,6}
OUTPUT: 9
*/

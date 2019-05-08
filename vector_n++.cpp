#include <iostream>
#include <vector>

std::vector<int> plusPlusN(std::vector<int> v);

int main()
{
    // create vector and pass into function
    std::vector<int> v {9}; 
    std::vector<int> retVal = plusPlusN(v); 
    
    // display returned vector
    std::cout << "[";
    for (int i = 0; i < retVal.size(); i++)
    {
        std::cout << retVal.at(i);
        if (i == retVal.size() - 1)
            std::cout << "";
        else
            std::cout << ",";
    }
    std::cout << "]";

    return 0;
}

/**
* FUNCTION SIGNATURE: vector<int> plusPlusN(vector<int> v)
 * PURPOSE: increments vector by one
 * PARAMETER:
 *     vector<int> v, vector to be incremented
 * RETURN VALUE:
 *     incremented vector
*/
std::vector<int> plusPlusN(std::vector<int> v)
{
    int lastElement = v.size() - 1;
    
    v[lastElement]++;
    for (int i = lastElement; i != -1; i--)
    {
        if (v[i] == 10)
        {
            v[i] = 0;
            if (i == 0)
                v.insert(v.begin(), 1);
            else
                v[i - 1]++;
        }
    }
    return v;
}

/* --SAMPLE OUTPUT--
INPUT: {8,8,8,8,8,8,8,8}
OUTPUT: [8,8,8,8,8,8,8,9]

INPUT: {9,9,9,9,9,9,9,9,9,9,9,9} 
OUTPUT: [1,0,0,0,0,0,0,0,0,0,0,0,0]

INPUT: {1,2,3}
OUTPUT: [1,2,4]

INPUT: {1,9,9}
OUTPUT: [2,0,0]
*/

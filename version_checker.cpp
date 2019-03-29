/**
 * Assignment#5.1
 * DUE: 3/25/19
 * NAME: Ryan Hathcock
 * PURPOSE: Compare two versions of a software product to determine which version is the latest.
 */

#include <iostream>
#include <string>
using namespace std;

int compareVersions(string ver1, string ver2);

int main()
{
    string ver1, ver2;

    cout << compareVersions("1.0", "1.1") << endl;  // -1
    cout << compareVersions("2.0", "2.0.1") << endl; // -1
    cout << compareVersions("0.1", "0.2") << endl; // -1
    cout << compareVersions("0.13.1", "0.13.2") << endl; // -1
    cout << compareVersions("300", "299.9.9") << endl; // 1
    cout << compareVersions("5.1.1", "4") << endl; // 1
    cout << compareVersions("300.23.15", "256") << endl; // 1
    cout << compareVersions("301.23", "301.2.1") << endl; // 0
    cout << compareVersions(".48.7", ".47.8") << endl; // 1
    return 0;
}

/**
 * FUNCTION NAME: int compareVersions()
 * PURPOSE: 
 *     to compare two software versions and determine which is the latest.
 * PARAMETER:
 *     string ver1, string ver2
 * RETURN VALUE:
 *     integer: if ver1 > ver2: return 1. 
 *              if ver1 < ver2: return -1.
 *              otherwise: return 0.
 * FUNCTION SINGATURE:
 *     int compareVersions(string ver1, string ver2)
 */
int compareVersions(string ver1, string ver2)
{ 
    int dotCounter = 0, firstDot = 0, secondDot = 0, previousDecimal = 0, ver1Major = 0, ver1Minor = 0, 
        ver1Revision = 0, ver2Major = 0, ver2Minor = 0, ver2Revision = 0;

    // store dot positions
    for (int i = 0; i < ver1.size(); i++)
    {
        if (ver1[i] == '.')
        {
            dotCounter++;
            if (dotCounter == 1)
                firstDot = i;
            else if (dotCounter == 2)
                secondDot = i;
        }
    }

    // VERSION 1: store major, minor, and revision into integer variables
    if (dotCounter == 0)
    {
        ver1Major = stoi(ver1);
        ver1Minor = 0;
        ver1Revision = 0;
    }
    else if (dotCounter == 1)
    {
        if (firstDot == 0)
            ver1Major = 0;
        else
            ver1Major = stoi(ver1.substr(0, firstDot));
        
        ver1Minor = stoi(ver1.substr(firstDot + 1, ver1.size() - firstDot));
        ver1Revision = 0;
    }
    else if (dotCounter == 2)
    {
        if (firstDot == 0)
            ver1Major = 0;
        else
            ver1Major = stoi(ver1.substr(0, firstDot));
        
        ver1Minor = stoi(ver1.substr(firstDot + 1, secondDot - (firstDot + 1)));
        ver1Revision = stoi(ver1.substr(secondDot + 1, ver1.size() - secondDot));
    }
    


    
        cout << ver1Major << "." << ver1Minor << "." << ver1Revision << endl;



    //return firstDot;
}

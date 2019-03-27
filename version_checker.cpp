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

    /*
    cout << compareVersions("1.0", "1.1") << endl;  // -1
    cout << compareVersions("2.0", "2.0.1") << endl; // -1
    cout << compareVersions("0.1", "0.2") << endl; // -1
    cout << compareVersions("0.13.1", "0.13.2") << endl; // -1
    cout << compareVersions("300", "299.9.9") << endl; // 1
    cout << compareVersions("5.1.1", "4") << endl; // 1
    */
    cout << compareVersions("300.23.15", "256") << endl; // 1
    cout << compareVersions("301.23", "301.2.1") << endl; // 0

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
    string temp; 
    int decimalCounter = 0, previousDecimal = 0, ver1Major = 0, ver1Minor = 0, 
        ver1Revision = 0, ver2Major = 0, ver2Minor = 0, ver2Revision = 0;

    for (int i = 0; i < ver1.size(); i++)
    {
        if ((ver1[i] == '.'))
        {
            if (decimalCounter == 0) // store MAJOR 301.23.15, 301.23
            {
                ver1Major = stoi(ver1.substr(0, i));
                ver1.erase(0, i + 1);
                i = 0;
            }
            else if (decimalCounter == 1) // store minor
            {
                ver1Minor = stoi(ver1.substr(0, i));
                ver1.erase(0, i + 1);
                ver1Revision = stoi(ver1); 
            }
             decimalCounter++;

        }
    }
    return ver1Revision;
}


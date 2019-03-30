#include <iostream>
#include <string>
using namespace std;

int versionCompare(string ver1, string ver2);

int main()
{
    string ver1, ver2;

    cout << versionCompare("1.0", "1.1") << endl;  // -1
    cout << versionCompare("2.0", "2.0.1") << endl; // -1
    cout << versionCompare("0.1", "0.2") << endl; // -1
    cout << versionCompare("0.13.1", "0.13.2") << endl; // -1
    cout << versionCompare("300", "299.9.9") << endl; // 1
    cout << versionCompare("5.1.1", "4") << endl; // 1
    cout << versionCompare("300.23.15", "256") << endl; // 1
    cout << versionCompare("301.23.1", "301.23.1") << endl; // 0
    cout << versionCompare("850", "850.0.0") << endl; // 0
    cout << versionCompare(".0.1", ".0.2") << endl; // -1
    cout << versionCompare("3.1.1", "4") << endl; // -1
    cout << versionCompare("1.1", "1") << endl; // 1
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
int versionCompare(string ver1, string ver2)
{ 
    int dotCounter = 0, firstDot = 0, secondDot = 0, previousDecimal = 0, ver1Major = 0, ver1Minor = 0, 
        ver1Revision = 0, ver2Major = 0, ver2Minor = 0, ver2Revision = 0, comparisonResult = 0;

    // VERSION 1 ---------
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
    // store major, minor, and revision into integer variables
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

    // VERSION 2 ---------
    // store dot positions
    dotCounter = 0;
    firstDot = 0;
    secondDot = 0;

    for (int i = 0; i < ver2.size(); i++)
    {
        if (ver2[i] == '.')
        {
            dotCounter++;
            if (dotCounter == 1)
                firstDot = i;
            else if (dotCounter == 2)
                secondDot = i;
        }
    }
    // store major, minor, and revision into integer variables
    if (dotCounter == 0)
    {
        ver2Major = stoi(ver2);
        ver2Minor = 0;
        ver2Revision = 0;
    }
    else if (dotCounter == 1)
    {
        if (firstDot == 0)
            ver2Major = 0;
        else
            ver2Major = stoi(ver2.substr(0, firstDot));
        
        ver2Minor = stoi(ver2.substr(firstDot + 1, ver2.size() - firstDot));
        ver2Revision = 0;
    }
    else if (dotCounter == 2)
    {
        if (firstDot == 0)
            ver2Major = 0;
        else
            ver2Major = stoi(ver2.substr(0, firstDot));
        
        ver2Minor = stoi(ver2.substr(firstDot + 1, secondDot - (firstDot + 1)));
        ver2Revision = stoi(ver2.substr(secondDot + 1, ver2.size() - secondDot));
    }

    // ------ Comparison Test Cases -------
    // If ver1 > ver2: return 1
    // if ver1 < ver2: return -1
    // otherwise, return 0. 
    if (ver1Major > ver2Major)
        comparisonResult = 1;
    else if (ver1Major < ver2Major)
        comparisonResult = -1;
    else if (ver1Major == ver2Major)
    {
        if (ver1Minor > ver2Minor)
            comparisonResult = 1;
        else if (ver1Minor < ver2Minor)
            comparisonResult = -1;
        else if ((ver1Minor == ver2Minor) && (ver1Revision == ver2Revision))
            comparisonResult = 0;
        else if ((ver1Minor == ver2Minor) && (ver1Revision > ver2Revision))
            comparisonResult = 1;
        else if ((ver1Minor == ver2Minor) && (ver1Revision < ver2Revision))
            comparisonResult = -1;
    }

    return comparisonResult;
}

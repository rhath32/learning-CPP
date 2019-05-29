// This code takes an input string and finds a character that appears to consist of half the string length.

#include <iostream>
#include <string>
using namespace std;

char findHalfDuplicate(string s);

int main()
{
    cout << findHalfDuplicate("1a2a3a4a") << endl;
    cout << findHalfDuplicate("a2a3a1") << endl;
    cout << findHalfDuplicate("2aa3") << endl;
    cout << findHalfDuplicate("1j2j3j4j5j") << endl;
    cout << findHalfDuplicate("12345kkkkk");
    
    return 0;
}

char findHalfDuplicate(string s)
{
    char halfDuplicate;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        count = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (s[i] == s[j])
                count++; 
        }
        if (count == s.size() / 2)
	{
	     halfDuplicate = s[i];
	     break;
	}
    }
    return halfDuplicate;
}

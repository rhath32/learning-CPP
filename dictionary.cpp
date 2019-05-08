#include <iostream>
#include <string>
#include <unordered_set>

class CIS14
{
	public:
		bool isInputInDictionary(std::string* s, std::unordered_set<std::string> &dict);
};

// driver code
int main()
{
	std::string input = "applepiez";
	std::unordered_set<std::string> dictionary({ "apple", "pie" });
	CIS14 cis14;

	std::cout << cis14.isInputInDictionary(&input, dictionary);
	return 0;
}

/**
 * MEMBER FUNCTION NAME:
 *    isInputInDictionary
 * PURPOSE:
 *    This function is included in the CIS14 class. The function receives an input dictionary of strings
 *	  and an input string, then determines if the string is comprised of only words that are in the dictionary.
 * PARAMETER:
 *    string* s, pointer to input string
 *    unordered_set<string> &dict, reference to dictionary
 * RETURN VALUE:
 *    bool inDictionary, true(1) if word is comprised of only dictionary words, false(0) otherwise
 */
bool CIS14::isInputInDictionary(std::string* s, std::unordered_set<std::string> &dict)
{
	bool inDictionary = false;
	std::string word = *s, leftSide = "", rightSide = "";

	for (int i = 0; i < word.size() + 1; i++) // set i for substrings
	{
		leftSide = word.substr(0, i), rightSide = word.substr(i, word.size() - 1);
		std::unordered_set<std::string>::const_iterator itLeft = dict.find(leftSide);
		std::unordered_set<std::string>::const_iterator itRight = dict.find(rightSide);

		if (itLeft != dict.end()) // left exists in set 
		{
			if (itRight != dict.end() || rightSide.size() == 0) // right exists in set 
			{
				inDictionary = true;
			}
			else
			{
				std::string newWord = word.substr(i + 1, word.size() - 1);
				return isInputInDictionary(&newWord, dict);
			}
		}
	}
	return inDictionary;
}

/** ----SAMPLE OUTPUTS----
INPUT: "applepie", {"apple", "pie"}
OUTPUT: 1

INPUT: "hellonow", {"hello", "on", "hell", "now"}
OUTPUT: 1

INPUT: "hellonowl", {"hell", "on", "owl"}
OUTPUT: 1

INPUT: "joey", {"joe1", "joe"}
OUTPUT: 0
*/

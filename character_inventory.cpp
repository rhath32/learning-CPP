#include <iostream>
#include <string>

class Addresses
{
	public:
		int getNumPossibleSigns(std::string* letterInventory, std::string* addresses, int length);
};

int main()
{
	std::string addresses[] = {"123C","123A","123 ADA","567 CBA", "985 BAAAAC"};
	std::string inventory = "AAAABCCC123456789";
	int addrLength = sizeof(addresses) / sizeof(addresses[0]);
	Addresses addresses;

	std::cout << addresses.getNumPossibleSigns(&inventory, addresses, addrLength);
	return 0;
}

/**
 * MEMBER FUNCTION NAME:
 *    getNumPossibleSigns
 * PURPOSE:
 *    This function is a member of the Addresses class. It takes in a series of addresses in a string array
 *	  and compares each of them with the available letterInventory, returning the number of addresses 
 *	  that are POSSIBLE to form from the given letterInventory
 * PARAMETER:
 *    string* letterInventory, inventory of plastic letters available
 *    string* addresses, addresses requested from user
 *    int length, length of the array addresses[]
 * RETURN VALUE:
 *    int: the number of possible addresses that can be formed from your inventory of letters
 */
int Addresses::getNumPossibleSigns(std::string* letterInventory, std::string* addresses, int length)
{
	int possibleAddr = 0, currentChar = 0, addrCount[43] = { 0 }, invCount[43] = { 0 };
	int arrayLength = sizeof(addrCount) / sizeof(addrCount[0]);
	std::string letterInv = *letterInventory, currentAddr = "";

	// store counts of inventory letters into invCount[]
	for (int i = 0; i < letterInv.size(); i++)
	{
		currentChar = letterInv[i] - '0'; 
		invCount[currentChar]++;
	}
	// iterate through each address, store counts of each address into addrCount[], and compare counts to invCount[]
	for (int i = 0; i < length; i++) 
	{
		bool enoughLetters = true;
		currentAddr = addresses[i]; 

		for (int j = 0; j < currentAddr.size(); j++)
		{
			if (currentAddr[j] == ' ')
				j++;
			currentChar = currentAddr[j] - '0';
			addrCount[currentChar]++;
		}
		// compare currentAddr to letterInv
		for (int j = 0; j < arrayLength; j++)
		{
			if (addrCount[j] > invCount[j]) 
			{
				enoughLetters = false;
				break;
			}
		}
		// reset all currentAddr array elements to 0 for next count
		for (int j = 0; j < arrayLength; j++)
		{
			addrCount[j] = 0;
		}
		// increment total possible addresses
		if (enoughLetters == true)
			possibleAddr++;
	}
	return possibleAddr;
}

/** ----SAMPLE OUTPUTS----
INPUT: { "123C","123A","123 ADA" }, "AAAABCCC123456789"
OUTPUT: 2

INPUT: { "2 FIRST ST"," 13 PUN ST", "101 AKER" }, "ABCDEFGHIJKLMNORSTUVWXYZ1234567890"
OUTPUT: 0

INPUT: { "999 S ST", "A BAD ST", "B BAD ST" }, "ABCDAAST"
OUTPUT: 1
*/

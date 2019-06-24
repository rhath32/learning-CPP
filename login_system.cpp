/*
This program is used to create a simple login system for a set of 4 computer labs. 
It demonstrates basic object orientated programming with the LoginSystem class and various methods associated with it.
It also incorporates dynamic memory allocation and deallocation with the class constructor and destructor.
*/

#include <iostream>
#include <string>
#include <iomanip>

class LoginSystem 
{
	// 2D array holding Lab#s and corresponding Computer#s
	const int NUM_LABS = 4;
	const int NUM_COMPUTERS = 10;
	std::string** labs = new std::string*[NUM_LABS];

	public:
		LoginSystem();
		~LoginSystem();

		void showStatus();
		void showMenu();
		void login();
		void logout();
		void search();
};

// Dynamic allocation of 2D array - labs
LoginSystem::LoginSystem()
{
	// create columns
	for (int i = 0; i < NUM_LABS; i++)
		labs[i] = new std::string[NUM_COMPUTERS];
	
	// populate entire 2D array
	for (int i = 0; i < NUM_LABS; i++)
	{
		for (int j = 0; j < NUM_COMPUTERS; j++)
		{
			labs[i][j] = "empty";
		}
	}
}

// Dynamic DE-allocation of your 2D array, labs
LoginSystem::~LoginSystem()
{
	for (int i = 0; i < NUM_LABS; i++)
	{
		delete[] labs[i]; 	 
	}
	delete[] labs; 
}

// Prints current status of labs
void LoginSystem::showStatus()
{
	std::cout << "STATUS\n" << "Lab# " << std::setw(7) << "   Computers\n";

	for (int i = 0; i < NUM_LABS; i++)
	{
		std::cout << i + 1 << " " << std::setw(7);

		for (int j = 0; j < NUM_COMPUTERS; j++)
		{
			std::cout << j + 1 << ": " << labs[i][j] << " ";
		}
		std::cout << "\n";
	}
}

// Prints user option menu
void LoginSystem::showMenu()
{
	std::cout << "\n" << "SELECTION MENU\n";
	std::cout << "1. LOGIN\n";
	std::cout << "2. LOGOUT\n";
	std::cout << "3. SEARCH\n";
	std::cout << "4. QUIT\n";
}

// Retrieves and validates userID, labSelection, and pcSelection. 
// Logs user into requested computer if possible.
void LoginSystem::login()
{
	std::string userID = "";
	int labSelection = 0, pcSelection = 0;
	bool inputValid = true;

	// login input
	do 
	{
		std::cout << "Enter your 5-character ID to login: \n";
		std::cin >> userID;
	} while ((userID.length() != 5) || (userID == "empty"));

	// lab # input
	do
	{
		inputValid = true;
		std::cout << "Enter the lab# \n";
		std::cin >> labSelection;

		// check if interger value
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			inputValid = false;
		}
		else if (labSelection < 1 || labSelection > 4)
			inputValid = false;
		else
			inputValid = true;
	} while (inputValid == false);

	// computer # input
	do
	{
		inputValid = true;
		std::cout << "Enter the computer # \n";
		std::cin >> pcSelection;

		// check if input is integer & in range
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			inputValid = false;
		}
		else if (pcSelection < 1 || pcSelection > 10)
			inputValid = false;
		else
			inputValid = true;
	} while (inputValid == false);

	// check if computer is already in use
	if (labs[labSelection - 1][pcSelection - 1] != "empty")
	{
		std::cout << "ERROR: user " << labs[labSelection - 1][pcSelection - 1] <<
					" is already logged into that station. \n";
		return;
	}

	// check if user is already logged in elsewhere
	for (int i = 0; i < NUM_LABS; i++)
	{
		for (int j = 0; j < NUM_COMPUTERS; j++)
		{
			if (labs[i][j] == userID)
			{
				std::cout << userID << " is in Lab # " << i + 1 << 
							" at Computer # " << j + 1 << ". \n";
				return;
			}
		}
	}
	// log user in
	labs[labSelection - 1][pcSelection - 1] = userID;
}

// Retrieves userID to be logged out. Searches for userID in 2D array and logs out if possible.
void LoginSystem::logout()
{
	std::string userID = "";

	// logout userID input
	do
	{
		std::cout << "Enter your 5-character ID to logout: \n";
		std::cin >> userID;
	} while ((userID.length() != 5) || (userID == "empty"));

	// check if userID is logged in
	for (int i = 0; i < NUM_LABS; i++)
	{
		for (int j = 0; j < NUM_COMPUTERS; j++)
		{
			if (labs[i][j] == userID)
			{
				labs[i][j] = "empty";
				std::cout << "User " << userID << " is logged out. \n";
				return;
			}
		}
	}
	// user is not logged in
	std::cout << "That user is not logged in. \n";
}

// Searches 2D array for requested userID and returns lab# and computer#.
void LoginSystem::search()
{
	std::string userID = "";

	// search userID input
	do
	{
		std::cout << "Enter your 5-character ID to search: \n";
		std::cin >> userID;
	} while ((userID.length() != 5) || (userID == "empty"));

	// user logged in
	// print lab and PC #
	// check if userID is logged in
	for (int i = 0; i < NUM_LABS; i++)
	{
		for (int j = 0; j < NUM_COMPUTERS; j++)
		{
			if (labs[i][j] == userID)
			{
				std::cout << userID << " is in Lab #" << i + 1 <<
						  " at Computer #" << j + 1 << ".\n";
				return;
			}
		}
	}
	// user is not logged in
	std::cout << "That user is not logged in. \n";
}

int main()
{
	int selection = 0;
	bool validSelection = true;
	LoginSystem ls;

	// driver code
	do
	{
		validSelection = true;
		ls.showStatus();
		ls.showMenu();
		std::cin >> selection;

		// validate selection input
		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			validSelection = false;
		}
		else if (selection < 1 || selection > 4)
			validSelection = false;

		// input is valid. perform selected function
		if (validSelection == true)
		{
			switch (selection)
			{
				case 1:
				{
					ls.login(); break;
				}
				case 2:
				{
					ls.logout(); break;
				}
				case 3:
				{
					ls.search(); break;
				}
				case 4: return 0;
			}
		}
	} while (selection != 4);
}

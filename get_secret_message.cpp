#include <iostream>
#include <string>
#include <vector>

std::string getSecretMessage(std::string str);

int main()
{
   std::cout << getSecretMessage("professor can code") << "\n"; // prints "pcc"
   std::cout << getSecretMessage("                ") << "\n";  // prints nothing
   std::cout << getSecretMessage("pasadena") << "\n";  // prints "p"
   std::cout << getSecretMessage("professor       can      code   ") << "\n"; // prints "pcc"
   std::cout << getSecretMessage("    learning    c   +  +  is     fun  !  ") << "\n"; // prints lc++if!
   std::cout << getSecretMessage(" ") << "\n"; // prints nothing
   return 0;
}

/**
* FUNCTION SIGNATURE: string getSecretMessage(string str)
 * PURPOSE: get secret message by taking the first character from each word in the input sentence,
 *          in the order they appear
 * PARAMETER:
 *     str, the input sentence 
 * RETURN VALUE:
 *     The secret message
*/
std::string getSecretMessage(std::string str)
{
    std::string secretMessage = "";

    for (int i = 0; i < str.size(); i++)
    {
        if ((i == 0) && (str[i] != ' '))
            secretMessage += str[i];
        else if((str[i] != ' ') && (str[i - 1] == ' '))
            secretMessage += str[i];
    }
    return secretMessage;
}

/*-----SAMPLE OUTPUT------
pcc

p
pcc
lc++if!
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindrome(string);
string prepareString(string userInput);

int main()
{
	bool returnWhether;
	string userInput;
	string modifiedString;
	cout << "Please enter a string: " << endl;
	getline(cin, userInput);

	modifiedString = prepareString(userInput);

	cout << modifiedString<<endl;

	returnWhether = isPalindrome(modifiedString);
	if (returnWhether)
		cout << modifiedString << " is a palindrome" << endl;
	else 
		cout << modifiedString << " is not a palindrome" << endl;

}

string prepareString(string userInput)
{
	userInput.erase(remove(userInput.begin(), userInput.end(), ' '), userInput.end()); // the idea to use remove function came from stack overflow

	for (int i = 0, len = userInput.size(); i < len; i++)
	{
		userInput[i]=tolower(userInput[i]);
		if (ispunct(userInput[i]))
		{
			userInput.erase(i--, 1);
			len = userInput.size();
		}
	}

	return userInput;

}

bool isPalindrome(string word)
{
	if (word.length() == 0)
		exit(0);
	string firstLetter = word.substr(0, 1);
	string lastLetter = word.substr((word.length() - 1), 1);

	if (firstLetter == lastLetter)
	{
		word = word.substr((0 + 1), (word.length() - 2));
		cout << word << " " << word.length() << endl;  
		if (word.length() <= 1) 
			return 1; 
		return isPalindrome(word);
	}
	else 
		return false;
}

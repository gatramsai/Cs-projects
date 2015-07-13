using namespace std;
#include <iostream>
#include <string>
#include "Bank.h"

<<<<<<< HEAD
void displayAccountInfo(Bank);

int main()
{
	Bank accountList[10];
	int option;
	do
	{
=======
void displayAccountInfo(Bank);//prototype for the display fucntion

int main()
{
	int count = 0;//this will hold the current index of the array that will be modified
	int accountAmount = 0;//this will hold the amount of accounts that are created
	Bank accountList[10];//array to hold a max to 10 accounts
	int option;//will hold user input for the option
	do
	{
	mylabel:
>>>>>>> origin/classesBank1337
		cout << "1.	Create Bank object with values for accountNumber, name, and balance" << endl;
		cout << "2.	Create Bank object with no parameters" << endl;
		cout << "3.	Deposit to Bank account" << endl;
		cout << "4.	Withdraw from Bank account" << endl;
		cout << "5.	Display information for all accounts" << endl;
		cout << "6.	Exit the program." << endl;

		cout << "Please select an option : ";
<<<<<<< HEAD
		cin >> option;  

		if (option == 1)
		{
			int count = 0;
			int userNumber;
=======
		cin >> option;

		if (option == 1)//this will create an account with parameters
		{
			int userNumber;
			
>>>>>>> origin/classesBank1337
			string userName;
			double userBalance;
			cout << "Please enter the account number: " << endl;
			cin >> userNumber;
<<<<<<< HEAD
			cout << "Please enter an account name: "<<endl;
=======
			cout << "Please enter an account name without spaces: " << endl;
>>>>>>> origin/classesBank1337
			cin >> userName;
			cout << "Please enter the account balance: " << endl;
			cin >> userBalance;

<<<<<<< HEAD
			for (int ix = 0; ix < 10; ix++)
=======
			for (int ix = 0; ix < 10; ix++)//check for pre existant accoutn number
>>>>>>> origin/classesBank1337
			{
				if (accountList[ix].getAccountNumber() == userNumber)
				{
					cout << "This account number already exists!" << endl;
<<<<<<< HEAD
					break;
				}
			}

			accountList[count]=Bank(userNumber, userName, userBalance);

		}
		if (option == 2)
		{
			Bank account();
		}
		if (option == 3)
		{
			int number;
			double amount;
=======
					goto mylabel;//if it already exists then you must do back to the original menu system
				}
			}
		
			
			accountList[count] = Bank(userNumber, userName, userBalance);//if it is uique store in array
			accountAmount++;//increment to increase the account number
			count++;//increment is change index for next account
		}
		if (option == 2)//default constructor
		{
			Bank account();
			accountAmount++;
		}
		if (option == 3)//deposit function
		{
			int number;
			double amount;
			bool isInvalid;
>>>>>>> origin/classesBank1337
			cout << "Please enter the account number: " << endl;
			cin >> number;
			cout << "Please enter the deposit amount: " << endl;
			cin >> amount;
<<<<<<< HEAD

			for (int ix = 0; ix < 10; ix++)
			{
				if (accountList[ix].getAccountNumber() == number)
				{
					accountList[ix].deposit(amount);
					break;
				}
				else
				{
					cout << "Invalid account number!" << endl;
					break;
				}

			}
		}
			if (option == 4)
			{
				int number;
				double amount;
				cout << "Please enter the account number: " << endl;
				cin >> number;
				cout << "Please enter the withdrawal amount: " << endl;
				cin >> amount;

				for (int ix = 0; ix < 10; ix++)
				{
					if (accountList[ix].getAccountNumber() == number)
					{
						accountList[ix].withdraw(amount);
						break;
					}
					else
					{
						cout << "Invalid account number!" << endl;
						break;
					}

				}
			}
			if (option == 5)
			{
				for (int ix = 0; ix < 10; ix++)
				{
					displayAccountInfo(accountList[ix]);
				}
			}
		
	} while (option != 6);



return 0;
}

void displayAccountInfo(Bank object)
=======
			for (int ix = 0; ix < 10; ix++)
			{
				if (accountList[ix].getAccountNumber() == number)//if valid then deposit if not the program will display the error and go back
				{
					accountList[ix].deposit(amount);
					goto mylabel;//if valid it will go back to the loop
				}
			}
			cout << "Error!Please Enter a valid account number." << endl;
		}
		if (option == 4)//withdrawal
		{
			int number;
			double amount;
			cout << "Please enter the account number: " << endl;
			cin >> number;
			cout << "Please enter the withdrawal amount: " << endl;
			cin >> amount;

			for (int ix = 0; ix < 10; ix++)
			{
				if (accountList[ix].getAccountNumber() == number)//if valid then withdraw if not the program will display the error and go back
				{
					accountList[ix].withdraw(amount);
					goto mylabel;//if valid it will go back to the loop
				}
			}
			cout << "Error!Please Enter a valid account number." << endl;
		}
		if (option == 5)
		{
			for (int ix = 0; ix < accountAmount; ix++)
			{
				displayAccountInfo(accountList[ix]);
			}
		}
	} while (option != 6);
	return 0;
}

void displayAccountInfo(Bank object)//the display function
>>>>>>> origin/classesBank1337
{
	cout << "The account number is : " << object.getAccountNumber() << endl;
	cout << "The name is           : " << object.getName() << endl;
	cout << "The Balance is        : " << object.getBalance() << endl;
}
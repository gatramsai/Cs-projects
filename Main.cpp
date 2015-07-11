using namespace std;
#include <iostream>
#include <string>
#include "Bank.h"

void displayAccountInfo(Bank);

int main()
{
	Bank accountList[10];
	int option;
	do
	{
		cout << "1.	Create Bank object with values for accountNumber, name, and balance" << endl;
		cout << "2.	Create Bank object with no parameters" << endl;
		cout << "3.	Deposit to Bank account" << endl;
		cout << "4.	Withdraw from Bank account" << endl;
		cout << "5.	Display information for all accounts" << endl;
		cout << "6.	Exit the program." << endl;

		cout << "Please select an option : ";
		cin >> option;  

		if (option == 1)
		{
			int count = 0;
			int userNumber;
			string userName;
			double userBalance;
			cout << "Please enter the account number: " << endl;
			cin >> userNumber;
			cout << "Please enter an account name: "<<endl;
			cin >> userName;
			cout << "Please enter the account balance: " << endl;
			cin >> userBalance;

			for (int ix = 0; ix < 10; ix++)
			{
				if (accountList[ix].getAccountNumber() == userNumber)
				{
					cout << "This account number already exists!" << endl;
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
			cout << "Please enter the account number: " << endl;
			cin >> number;
			cout << "Please enter the deposit amount: " << endl;
			cin >> amount;

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
{
	cout << "The account number is : " << object.getAccountNumber() << endl;
	cout << "The name is           : " << object.getName() << endl;
	cout << "The Balance is        : " << object.getBalance() << endl;
}
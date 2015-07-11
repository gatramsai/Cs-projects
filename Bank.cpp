#include "Bank.h"
using namespace std;
#include <iostream>


Bank::Bank()
{
	accountNumber = 9999;
	name = "";
	balance = 0;
}


Bank::~Bank()
{
}

Bank::Bank(int newNumber, string newName, double newBalance)
{
	accountNumber = newNumber;
	name = newName;
	balance = newBalance;
}


void Bank::withdraw(double amount)
{ 
	double currentBalance = getBalance();
	if (currentBalance >= amount)
	{
		balance = balance - amount;
		cout << "New Balance = " << to_string(balance) << endl;
	}
	else
	{
		cout << "Insufficient balance" << endl;
	}
}
void Bank::deposit(double amount)
{
	balance = balance + amount;
}
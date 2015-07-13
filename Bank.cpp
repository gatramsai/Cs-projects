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

Bank::Bank(int newNumber, string newName, double newBalance)//this will create a object using the parameters given by the user
{
	accountNumber = newNumber;
	name = newName;
	balance = newBalance;
}


void Bank::withdraw(double amount)//this is the withdraw fucntion that will update the balance
{
	double currentBalance = getBalance();
	if (currentBalance >= amount)
	{
		balance = balance - amount;
		cout << "New Balance = " << to_string(balance) << endl;//convert to string because you must also return the invalid if needed
	}
	else
	{
		cout << "Insufficient balance" << endl;
	}
}
void Bank::deposit(double amount)//this is the deposit fucntion that will update the balance
{
	balance = balance + amount;
}
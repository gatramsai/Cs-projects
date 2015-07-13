#include "Bank.h"
using namespace std;
#include <iostream>


<<<<<<< HEAD
=======

>>>>>>> origin/classesBank1337
Bank::Bank()
{
	accountNumber = 9999;
	name = "";
	balance = 0;
}


Bank::~Bank()
{
}

<<<<<<< HEAD
Bank::Bank(int newNumber, string newName, double newBalance)
=======
Bank::Bank(int newNumber, string newName, double newBalance)//this will create a object using the parameters given by the user
>>>>>>> origin/classesBank1337
{
	accountNumber = newNumber;
	name = newName;
	balance = newBalance;
}


<<<<<<< HEAD
void Bank::withdraw(double amount)
{ 
=======
void Bank::withdraw(double amount)//this is the withdraw fucntion that will update the balance
{
>>>>>>> origin/classesBank1337
	double currentBalance = getBalance();
	if (currentBalance >= amount)
	{
		balance = balance - amount;
<<<<<<< HEAD
		cout << "New Balance = " << to_string(balance) << endl;
=======
		cout << "New Balance = " << to_string(balance) << endl;//convert to string because you must also return the invalid if needed
>>>>>>> origin/classesBank1337
	}
	else
	{
		cout << "Insufficient balance" << endl;
	}
}
<<<<<<< HEAD
void Bank::deposit(double amount)
=======
void Bank::deposit(double amount)//this is the deposit fucntion that will update the balance
>>>>>>> origin/classesBank1337
{
	balance = balance + amount;
}
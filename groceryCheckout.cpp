//NAME : SAI GATRAM
//CLASS : CS 1337.004
//DATE : 3/14/15
//DESCRIPTION : this program will perform a grocery check-out procedure for a simple store using a dynamic array of pointers to structures to store info.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Product  // This is the structure Product
{
	string priceLookupCode;
	string productName;
	int salesType;
	double price;
	double inventory;
};

int COUNT = 0; // This number will store the exact amount of products in the store
const int SIZE = 100; // the number is the max amount of products
Product *proPtr; // 

bool readInventory(string filename); // prototype for the file reading function
double checkout();//proptotype for the checkout function 
bool updateInventory(string filename); //This function updates the inventory before terminating the program. 

int main()
{
	double total = 0;
	readInventory("products.txt"); //call the read fucntion which will create a "data base"

	int userChoice;
	cout << "Enter a 1 to checkout or enter 2 close the store and exit." << endl; // The menu option to begin checkout
	do
	{
		cout << "Enter choice: ";
		cin >> userChoice;
	} while ((userChoice<1) || (userChoice>2));
	
	do
	{
		if (userChoice == 1)
		{

			total = checkout(); // stores the total and brings it to the main function for discount
			break;
		}
		else//once 0 is entered it will update and end
		{
			 updateInventory("products.txt");
			 return 0;
		}
			
	} while (userChoice != 2);

	if (total > 50) // The loop to take the discount for the total
	{
		cout << "BEFORE 5% discount, Total is $ " << total << endl;
		total = total *.95;
		cout << "Since total is over $50, AFTER 5% discount the New total is $ " << total << endl;
	}
	else
		cout << "total cost is " << total << endl;
	
}

//this function will take the file and enter the contents into an array of structures
bool readInventory(string filename)
{

	ifstream inputFile;
	inputFile.open(filename);

	proPtr = new Product[SIZE];//after the file is opened, dynamic array of Products is created to store up to 100 elements, and then it reads the file content line by line, 

	//these variables will store the files data 
	string priceLookupCode; 
	string productName;
	bool salesType;
	double price;
	double inventory;

	while (inputFile >> priceLookupCode >> productName >> salesType >> price >> inventory) // this will check if the file can read and will input values. will check for eof.
	{
		//assign the array of structs to its data
		proPtr[COUNT].priceLookupCode = priceLookupCode;
		proPtr[COUNT].productName = productName;
		proPtr[COUNT].salesType = salesType;
		proPtr[COUNT].price = price;
		proPtr[COUNT].inventory = inventory;
		COUNT++; // this will count the amount of products and update the global
	}
	return true;
}


//this function will perform the checkout operations
double checkout()
{
	//these variables will store user input among other things
	string pluCode;
	double total = 0;
	double weight = 0;
	int productIndex;
	string valid;

	do
	{
		pluCode = "-1";
		cout << "Enter a PLU code or type 0 to indicate end of checkout." << endl;
		cin >> pluCode;
		string check = "-1"; // this will be used to see is a PLU code match is found
		
		if (pluCode == "0")//If 0 is entered end checkout and update the file
		{
			updateInventory("products.txt"); //call will update file
			break;
		}

		for (int k = 0; k < COUNT; k++) // only scan for the available products and not 100 max
		{
			if (proPtr[k].priceLookupCode == pluCode) // If a PLU code is matched assign the index and continue checkout
			{
				productIndex = k;
				check = pluCode;
				break; // this break is to stop unnecessary searches 
			}
		}

		if (check == "-1") // if PLU match is not found, then ask again for PLU codes
		{
			cout << "PLU code was invalid.Try again." << endl;
			continue;
		}

		if (proPtr[productIndex].salesType == 0) // If 0, then it has inventory in units
		{
			cout << "Enter Unit Amount." << endl;
			cin >> weight;
			if ((weight > proPtr[productIndex].inventory) || (weight < 0)) // check if the inventory is a valid number 
			{
				cout << "Invalid Unit! The Unit must be less than the inventory and greater than 0. The Current inventory -  " << proPtr[productIndex].inventory << endl;
				continue;
			}

		}
		else // if not 0 it is 1, so inventory is by weight
		{
			cout << "Enter Pounds Needed." << endl;
			cin >> weight;
			if ((weight > proPtr[productIndex].inventory) || (weight < 0))//make sure weight is valid
			{
				cout << "Invalid Unit! The Unit must be less than the inventory and greater than 0. The Current inventory -  " << proPtr[productIndex].inventory << endl;
				continue;
			}

		}
		total = total + (weight * proPtr[productIndex].price); // accumulator for total
		proPtr[productIndex].inventory -= weight; // change for the inventory numbers
		cout << proPtr[productIndex].productName << "  -              " << setw(8)<< "$"<<(weight * proPtr[productIndex].price) << endl; //print the cost for item
		cout << "The current total is : " << setw(8)<< "$"<<total << endl; //print accumulated total
	}while(pluCode != "0");
	
	return total;

}

//this function will update the inventory
bool updateInventory(string filename)
{

	ofstream outputFile;
	outputFile.open(filename);

	if (outputFile) //actual updating of file data
	{
		for (int k = 0; k < COUNT; k++) // by using COUNT the file data will be for only the products available and not the 100 max
			outputFile << proPtr[k].priceLookupCode << " " << proPtr[k].productName << " " << proPtr[k].salesType << " " << proPtr[k].price << " " << proPtr[k].inventory << endl;
		return true;
	}
	else
	{
		cout << "Can't open file." << endl;
		return false;
	}
	
}

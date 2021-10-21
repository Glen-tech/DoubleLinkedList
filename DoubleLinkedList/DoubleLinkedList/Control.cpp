#include "Control.h"
#include "Company.h"
#include "Employes.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

enum choise {EMPLOYER = 1, HIGHER_STAFF, SUPPLIER, EXIT};

control::control()
{
	input = "";
}

void control::insertChoise()
{
	Company* point;
	Employes test;

	print();

	cin >> input;
	
		while (true)
		{

			switch (stoi(input))
			{
			case EMPLOYER: cout << "employer" << endl;
				point = &test;
				point->insert();
				break;


			case HIGHER_STAFF: cout << "Higher staff" << endl; break;
			case SUPPLIER: cout << "Supplier" << endl; break;

			case EXIT: cout << "EXIT" << endl;
				exit(0);
				break;

			default:
				cout << "Wrong choise terminate program, Try again" << endl;
				exit(0);

			}

			cin >> input;
		}

}

void control::print()
{
	cout << "Choise what you want to do" << endl;
	cout << "Press 1 to add employer" << endl;
	cout << "Press 2 to add higher staff" << endl;
	cout << "Press 3 to add supplier" << endl;

}



control::~control()
{
}

#include "Employes.h"
#include "control.h"
#include <iostream>
using namespace std;

enum employer {ADD = 1 , DELETE, PRINT, GO_BACK};

Employes::Employes()
{

    input = "";
    IntInput = 0;

    new_node = nullptr;


    adding.name = "";
    adding.function = "";
    adding.fpaycheck = 0;

    workers.fpayCheck = 0;
    workers.next = nullptr;
    workers.prev = nullptr;
    workers.HeadEmployes = nullptr;
}



void Employes::insert()
{
    control goback;
    print(); // show instructions;

    cin >> input;
    IntInput = stoi(input);

    while (true)
    {
        switch (stoi(input))
        {
            case ADD: 
                cout << "Enter name" << endl;
                cin >> adding.name;
                cout << "Enter function" << endl;
                cin >> adding.function;
                cout << "Enter Paycheck" << endl;
                cin >> adding.fpaycheck;
                pushEmployes(&workers.HeadEmployes, adding.name, adding.function, adding.fpaycheck);
                break;
            case DELETE: cout << "work in progress" << endl; break;

            case PRINT:  cout << "work in progress" << endl; break;

            case GO_BACK: return; // exit while loop and return

            default: cout << "Something went wrong , goning back" << endl;
            break;
        }

        cin >> input;
        IntInput = stoi(input);
    }

    goback.insertChoise();
   
}

void Employes::print()
{
        cout << "Choise what you want to do" << endl;
        cout << "Press 1 to add  employer" << endl;
        cout << "Press 2 to delete employer" << endl;
        cout << "Press 3 to print" << endl;
        cout << "Press 4 to go back" << endl;
}


void Employes::pushEmployes(employes** headEmployes, string nameEmployer, string functionEmployer, float payCheckEmployer)
{
    employes* new_node = new employes();
    new_node->name = nameEmployer;
    new_node->function = functionEmployer;
    new_node->fpayCheck = payCheckEmployer;

    new_node->next = *headEmployes;
    new_node->prev = NULL;

    if ((*headEmployes) != NULL)
    {
        (*headEmployes)->prev = new_node;
    }

    *headEmployes = new_node;

   
}

void Employes::printEmployes(employes *new_node)
{
    while (new_node != NULL)
    {
        cout << new_node->name << endl;
        cout << new_node->function << endl;
        cout << new_node->fpayCheck << endl;
    }
}

Employes::~Employes()
{
    delete workers.next;
    delete workers.prev;
    delete workers.HeadEmployes;
    delete new_node;
}

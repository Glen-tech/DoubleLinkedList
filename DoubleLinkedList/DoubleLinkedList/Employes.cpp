#include "Employes.h"
#include "control.h"
#include <iostream>
using namespace std;

enum employer {ADD = 1 , DELETE, PRINT_FORWARD, PRINT_BACKWARD, SEARCH,GO_BACK};

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

    while (true)
    {
        switch (stoi(input))
        {
            case ADD: 
                /*cout << "Enter name" << endl;
                cin >> adding.name;
                cout << "Enter function" << endl;
                cin >> adding.function;
                cout << "Enter Paycheck" << endl;
                cin >> adding.fpaycheck;
                pushEmployes(&workers.HeadEmployes, adding.name, adding.function, adding.fpaycheck);*/

                pushEmployes(&workers.HeadEmployes, "Glen", "Beetje vanalles", 1600);
                pushEmployes(&workers.HeadEmployes, "Maud", "Goed haar best doen", 1500);
                pushEmployes(&workers.HeadEmployes, "Eric", "Beetje kaal", 3000);
                pushEmployes(&workers.HeadEmployes, "Eliane", "Zorgen voor oudjes", 2500);
                pushEmployes(&workers.HeadEmployes, "Tara", "Iets met rechten", 2400);

                break;
            case DELETE: cout << "work in progress" << endl; break;

            case PRINT_FORWARD:   printEmployesForward(&workers.HeadEmployes);  break;

            case PRINT_BACKWARD:  printEmployesBackward(&workers.HeadEmployes); break;

            case SEARCH: cout << "work in progress" << endl; break;

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
        cout << "Press 3 to print forward" << endl;
        cout << "Press 4 to print backward" << endl;
        cout << "Press 5 to go back" << endl;
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
        (*headEmployes)->prev = new_node; // set prev to next
    }

    *headEmployes = new_node; // head is now the new_node for adding

   
}

void Employes::printEmployesForward(employes **print_node_forward_head)
{
    struct employes* tail = *print_node_forward_head; // tail is beginning of the list

    while (tail != nullptr)
    {
        cout << tail->name << endl;
        cout << tail->function << endl;
        cout << tail->fpayCheck << endl;

        tail = tail->next; // go to next node
    }
}

void Employes::printEmployesBackward(employes** print_node_backwards_head)
{
    struct employes* tail = *print_node_backwards_head; // tail is beginning of the list
    
    while (tail->next != nullptr) // go to end of the double linked list
    {
        tail = tail->next;
    }

    while(tail != nullptr) // no print backwards
    {
        cout << tail->name << endl;
        cout << tail->function << endl;
        cout << tail->fpayCheck << endl;

        tail = tail->prev; // go to prev node
    }

}

void Employes::search_node(employes** search_node_head)
{
    // work in progress
}


Employes::~Employes()
{
    delete workers.next;
    delete workers.prev;
    delete workers.HeadEmployes;
    delete new_node;
}

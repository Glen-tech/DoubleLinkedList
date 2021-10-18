#include "Employes.h"
#include <iostream>
using namespace std;

Employes::Employes()
{

    workers.payCheck = 0;
    workers.next = nullptr;
    workers.prev = nullptr;
    workers.HeadEmployes = nullptr;
}

void Employes::insert()
{
    pushEmployes(&workers.HeadEmployes, "Glen", "Klusjesman", 1600);
}

void Employes::pushEmployes(employes** headEmployes, string nameEmployer, string functionEmployer, float payCheckEmployer)
{
    struct employes* new_node = new employes();

    new_node->name = nameEmployer;
    new_node->function = functionEmployer;
    new_node->payCheck = payCheckEmployer;

    new_node->next = *headEmployes;
    new_node->prev = NULL;

    if ((*headEmployes) != NULL)
    {
        (*headEmployes)->prev = new_node;
    }

    *headEmployes = new_node;

    printEmployes(new_node);
   
}

void Employes::printEmployes(employes* node)
{
    cout << node->name << endl;
    cout << node->function << endl;
    cout << node->payCheck << endl;
}

Employes::~Employes()
{
    delete workers.next;
    delete workers.prev;
    delete workers.HeadEmployes;
}

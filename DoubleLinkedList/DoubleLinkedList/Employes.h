#pragma once

#include <string>
#include "Company.h"

using namespace std;

class Employes : public Company
{
public:

	Employes();

    string input;
    string spaycheck;
    string search;

    int IntInput;

    struct employes* new_node;


    void insert();
    void print();

    struct AddEmployes
    {
        string name;
        string function;
        float fpaycheck;
    }adding;

    struct employes
    {
        string name;
        string function;
        float fpayCheck;
        int yearsOfService;

        struct employes* prev;
        struct employes* next;
        struct employes* HeadEmployes;


    } workers;

    void pushEmployes(employes** headEmployes, string nameEmployer, string functionEmployer, float payCheckEmployer);
    void printEmployesForward(employes ** PrintHead);
    void printEmployesBackward(employes** PrintHead);
    void search_node(employes** Printhead);



	~Employes();

};

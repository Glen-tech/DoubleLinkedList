#pragma once

#include <string>
#include "Company.h"

using namespace std;

class Employes : public Company
{
public:

	Employes();


    void insert();

    struct employes
    {
        string name;
        string function;
        float payCheck;
        int yearsOfService;

        struct employes* prev;
        struct employes* next;
        struct employes* HeadEmployes;


    } workers;

    void pushEmployes(employes** headEmployes, string nameEmployer, string functionEmployer, float payCheckEmployer);
    void printEmployes(employes* node);



	~Employes();

};

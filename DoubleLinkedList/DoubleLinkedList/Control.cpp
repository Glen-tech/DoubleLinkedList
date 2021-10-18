#include "Control.h"
#include "Company.h"
#include "Employes.h"

control::control()
{
}

void control::insertChoise()
{
	Company* point;
	Employes test;

	point = &test;
	point->insert();
}

control::~control()
{
}

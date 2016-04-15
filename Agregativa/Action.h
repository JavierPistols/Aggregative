#pragma once
#include "DB.h"
#include "Individual.h"
//#include "Manipular.h"
#include "Population.h"
class Action
{
public:
	Action();
	~Action();

public:
	Population pop1;
	Population pop2;
	Population * newe;
	Population * oldy;
	Population * temp;
	DB theDB;
	int runs;
};


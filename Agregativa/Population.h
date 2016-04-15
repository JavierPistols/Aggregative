#pragma once
#include "Individual.h"
#include "DB.h"
#include "Smethods.h"
#include <vector>
#include <iostream>
using namespace std;
class Population
{
public:
	Population(int size = 20);////////////////
	~Population();
	void initialize(DB &gameData, float presupuesto = 10000);/////////////
	void printIndi(Individual &indi);

public:
	Individual *v_thePop;
	//float presupuesto;


public:
	float fitGame(int position, DB & games);
	float evalFunc(Individual & evaluated, DB & games);
	Individual mutation(Individual mutant, DB &theDB,Individual &res, float presupuesto = 10000);

	void fillUP(Population * newy, Population * oldy, Individual &fath, Individual &moth, Individual &res, DB & games, float presupuesto = 10000);////////////////

	Individual selection(Population & pop);
	void sort(Population & pop);
	void printVecP(Population * pop);
	pair<Individual,Individual> crossing(Individual father,Individual mother,Individual &fath, Individual &moth);
	
};


#include "Smethods.h"



Smethods::Smethods()
{
}


Smethods::~Smethods()
{
}

int Smethods::random(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}



double Smethods::random(double min, double max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(min, max);
	return dis(gen);
}
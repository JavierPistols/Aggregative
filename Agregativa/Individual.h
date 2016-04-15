#pragma once
#include <vector>
using namespace std;
class Individual
{
public:
	Individual();
	~Individual();

public:
	float fitness;
	float Tprice;
	float probability;
	bool * v_chromosome;
	//vector<bool> v_chromosome;

	//const int size = 10;
};


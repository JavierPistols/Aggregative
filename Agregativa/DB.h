#pragma once
#include <vector>
#include "Individual.h"
class DB
{
public:
	DB();
	~DB();



public:
	struct Info {
		float price;
		float calification;
		float clasification;
		float owners;
	};
	vector<Info>v_gamesInfo;



	Info i0, i1, i2, i3, i4, i5, i6, i7, i8, i9;
};


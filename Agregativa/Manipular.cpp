#include "Manipular.h"



Manipular::Manipular()
{
}


Manipular::~Manipular()
{
}



/*

float Manipular::fitGame(int position,DB &games)//saca el fitness por juego
{
	float totalFitness = 0, fitnessCal = 0, fitnessClas = 0, fitnessOw = 0;
	
	fitnessCal = games.v_gamesInfo.at(position).calification;
	fitnessCal *= 0.35;//porcentaje de importancia

	fitnessClas = games.v_gamesInfo.at(position).clasification;
	fitnessClas = (fitnessClas * 100) / 18; 
	fitnessClas *= 0.35;//porcentaje de importancia

	fitnessOw = games.v_gamesInfo.at(position).owners;
	fitnessOw = (fitnessOw * 100) / 1000000;
	fitnessOw *= 0.30;//porcentaje de importancia
	
	totalFitness = fitnessCal + fitnessClas + fitnessOw;
	return totalFitness;
}

float Manipular::evalFunc(Individual &evaluated,DB &games)//saca el fitness por solución
{
	float individualFitness = 0, precioTotal = 0;

	int vSize = evaluated.v_chromosome.size();
	for (int i = 0; i < vSize; i++)//recorre el vector de juegos escogidos
	{
		if (evaluated.v_chromosome.at(i))//si fue escogido obtiene el fitness de dicho juego
		{
			individualFitness += fitGame(i,games);
			precioTotal += games.v_gamesInfo.at(i).price;//sumar precio del objeto a la cuenta
		}
	}
	
	individualFitness /= vSize;//normaliza el fitness
	evaluated.Tprice = precioTotal;
	evaluated.fitness = individualFitness;//valor para el acomodo en el mapa
	return individualFitness;
}

void Manipular::sort(Population & pop)
{
	int size = 20;//tamaño de la poblacion
	bool swapp = true;
	while (swapp)
	{
		swapp = false;
		for (int i = 0; i < (size - 1); i++)
		{
			if (pop.v_thePop[i].fitness > pop.v_thePop[i + 1].fitness)
			{
				pop.v_thePop[i].fitness += pop.v_thePop[i + 1].fitness;
				pop.v_thePop[i + 1].fitness = pop.v_thePop[i].fitness - pop.v_thePop[i + 1].fitness;
				pop.v_thePop[i].fitness -= pop.v_thePop[i + 1].fitness;
				swapp = true;
			}
		}
	}
	
}

void Manipular::printVec(Population & pop)
{
	for (int i = 0; i < 20; i++)
		cout << endl << pop.v_thePop[i].fitness;
}

pair<Individual,Individual> Manipular::crossing(Population & pop)
{
	double probability;
	int pos;

	Individual father = Manipular::selection(pop);
	Individual mother = Manipular::selection(pop);
	Individual temp = father;
	probability = Smethods::random(0.0f, 1.0f);
	if (probability <= .75)
	{
		pos = Smethods::random(0, 10);
		for (int i = pos; i < 10; i++)
		{
			father.v_chromosome[pos] = mother.v_chromosome[pos];
			mother.v_chromosome[pos] = temp.v_chromosome[pos];
		}
	}
	return make_pair(father,mother);
}

void Manipular::mutation(Individual & mutant)
{
	double prob;
	for (int i = 0; i < 10;i++)
	{
		prob = Smethods::random(0.0f, 1.0f);
		if (prob <= 0.1f)
		{
			mutant.v_chromosome.at(i) = !mutant.v_chromosome.at(i);
		}
	}
}

void Manipular::fillUP(Population * newy,Population * oldy)
{	
	bool incomplete = true;
	pair<Individual, Individual> currPair;
	int ref = 0;
	Individual *position;
	position = newy->v_thePop;
	do
	{
		currPair = Manipular::crossing(*oldy);
		Manipular::mutation(currPair.first);

		if (ref < 20)
		{
			newy->v_thePop[ref] = currPair.first;
			ref++;
		}
		if (ref < 20)
		{
			Manipular::mutation(currPair.second);
			newy->v_thePop[ref] = currPair.second;
			ref++;
		}
	} while (ref < 20);
}



Individual Manipular::selection(Population & pop)//SELECCION
{
	float totalFitPOP = 0;
	float flag,sofar = 0;
	for (int i = 0; i < 20; i++)//obtiene total de fitness en la pop
	{
		totalFitPOP += pop.v_thePop[i].fitness;
	}
	for (int i = 0; i < 20; i++)//obtiene la probabilidad de cada individuo
	{
		pop.v_thePop[i].probability = pop.v_thePop[i].fitness / totalFitPOP;
	}
	flag = Smethods::random(0.0,1.0);

	for (int i = 0; i < 20; i++)//elige segun la probabilidad
	{
		if (sofar > flag)
			return pop.v_thePop[i];
		sofar += pop.v_thePop[i].probability;
	}
}*/





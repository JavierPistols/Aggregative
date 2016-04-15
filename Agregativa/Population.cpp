#include "Population.h"



Population::Population(int size)
{
	v_thePop = new Individual[size];
	//presupuesto = presupuesto;
}


Population::~Population()
{
}

void Population::initialize(DB &gameData, float presupuesto)//inicializa la población con individuos aleatorios en el multimapa de población
{
	int fill = 0;
	int indSize = 10;//tamaño de los individuos en poblacion
	float currentPrice = 0;//cuenta
	bool done = false;
	bool pass = false;
	int randomPos;
	int pSize = 20;//tamaño de población
	fill = 0;//deja el while como estaba cambia in por fill
	for (int in = 0; in < 20; in ++)
	{
		currentPrice = 0;
		done = false;
		for (int i = 0; i < indSize; i++)
		{
			
			v_thePop[in].v_chromosome[i] = Smethods::random(0, 1);//escoger o no un objeto
			if(v_thePop[in].v_chromosome[i])//si se eligio el objeto
			currentPrice += gameData.v_gamesInfo.at(i).price;//sumar precio del objeto a la cuenta
			
		}
		do {//forza que las soluciones no se pasen del presupuesto
			if (currentPrice > presupuesto)//si lo hacen elige un elemento al azar y lo deselecciona
			{
				pass = false;
				while (!pass)
				{
					randomPos = Smethods::random((int)0, 9);
					if (v_thePop[in].v_chromosome[randomPos])
					{
						v_thePop[in].v_chromosome[randomPos] = false;
						pass = true;
					}
				}
				currentPrice = 0;
				for (int i = 0; i < indSize; i++)
					currentPrice += gameData.v_gamesInfo.at(i).price;//sumar precio del objeto a la cuenta
			}
			else
				done = true;
		} while (!done);
		v_thePop[in].Tprice = currentPrice;
		evalFunc(v_thePop[in],gameData);//obtiene el fitness del Individuo y lo asigna a su variable fitness

		//cout << endl << currentPrice << "  " << in;
		
	}
}//CHECK






float Population::fitGame(int position, DB &games)//saca el fitness por juego.La posicion es del vector de juegos
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
}//CHECK

float Population::evalFunc(Individual &evaluated, DB &games)//saca el fitness por solución(individuo)
{
	float individualFitness = 0, precioTotal = 0;

	int vSize = 10;//tamaño de la solucion

	for (int i = 0; i < vSize; i++)//recorre el vector de juegos escogidos
	{
		if (evaluated.v_chromosome[i]) //si fue escogido 
		{
			individualFitness += fitGame(i, games);//obtiene el fitness de dicho juego
			//cout<< "  "<<fitGame(i, games);
			precioTotal += games.v_gamesInfo.at(i).price;//sumar precio del objeto a la cuenta
		}
	}
	
	individualFitness /= vSize;//normaliza el fitness
	evaluated.Tprice = precioTotal;//asigna el precio al individuo 
	evaluated.fitness = individualFitness;//valor para el ordenamiento del vector de soluciones
	return individualFitness;
}//CHECK

void Population::sort(Population & pop)
{
	int size = 20;//tamaño de la poblacion
	bool swapp = true;
	while (swapp)
	{
		swapp = false;
		for (int i = 0; i < (size - 1); i++)
		{
			if (pop.v_thePop[i].fitness < pop.v_thePop[i + 1].fitness)
			{
				pop.v_thePop[i].fitness += pop.v_thePop[i + 1].fitness;
				pop.v_thePop[i + 1].fitness = pop.v_thePop[i].fitness - pop.v_thePop[i + 1].fitness;
				pop.v_thePop[i].fitness -= pop.v_thePop[i + 1].fitness;
				swapp = true;
			}
		}
	}

}//CHECK

void Population::printVecP(Population * pop)//IMPRIME TODA LA POBLACION
{
	for (int i = 0; i < 20; i++)
		cout << endl << pop->v_thePop[i].fitness;
}//CHECK

pair<Individual,Individual> Population::crossing(Individual father, Individual mother, Individual &fath,Individual &moth)//Realiza el cruzamiento 
{
	double probability;
	int pos;
	Individual temp ;
	temp = father;

	//Individual *fath = new Individual;
	//Individual *moth = new Individual;

	fath.fitness = father.fitness;
	fath.probability = father.probability;
	fath.Tprice = father.Tprice;
	moth.fitness = mother.fitness;
	moth.probability = mother.probability;
	moth.Tprice = mother.Tprice;

	for (int i = 0; i < 10; i++)
	{
		fath.v_chromosome[i] = father.v_chromosome[i];
		moth.v_chromosome[i] = mother.v_chromosome[i];
	}

	probability = Smethods::random(0.0f, 1.0f);

	/*for (int i = pos; i < 10; i++)
	{
		temp.v_chromosome[i]
	}*/


	/*cout <<  endl << "mam ";
	for (int i = 0; i < 10; i++) cout << " " << moth->v_chromosome[i];
	cout << endl << "dad " ;
	for (int i = 0; i < 10; i++) cout << " " << fath->v_chromosome[i];*/
	bool hi = true;//
	//if (probability <= .75)//

	if(hi)
	{
		pos = Smethods::random(0, 10);
		//cout << endl << pos;//IMPRIME POS
		//cout << endl << "index";
		for (int i = pos; i < 10; i++)
		{
			//cout << " "<<i;
			fath.v_chromosome[i] = mother.v_chromosome[i];
			moth.v_chromosome[i] = temp.v_chromosome[i];
		}
		/*cout << endl << "mutant " ;
		for (int i = 0; i < 10; i++) cout << " " << father.v_chromosome[i];*/

	}
	
	return make_pair(fath,moth);
}//CHECK

Individual Population::mutation(Individual  mutant, DB &theDB,Individual &res,float presupuesto)//mutacion llama a random
{
	//Individual *indi = new Individual;
	res.fitness = mutant.fitness;
	res.probability = mutant.fitness;
	res.Tprice = mutant.Tprice;
	for (int i = 0; i < 10; i++)
	{
		res.v_chromosome[i] = mutant.v_chromosome[i];
	}
	double prob;
	bool done = false,pass;
	float currentPrice = 0;
	int randomPos;
	for (int i = 0; i < 10;i++)
	{
		prob = Smethods::random(0.0f, 1.0f);
		if (prob <= 0.1f)
		{
			mutant.v_chromosome[i] = !mutant.v_chromosome[i];
			currentPrice = 0;
			for (int i = 0; i < 10; i++)
				currentPrice += theDB.v_gamesInfo.at(i).price;
			do {//forza que las soluciones no se pasen del presupuesto
				if (currentPrice > presupuesto)//si lo hacen elige un elemento al azar y lo deselecciona
				{
					pass = false;
					while (!pass)//you shall not pass
					{
						randomPos = Smethods::random((int)0, 9);
						if (mutant.v_chromosome[randomPos])
						{
							mutant.v_chromosome[randomPos] = false;
							pass = true;
						}
					}
					currentPrice = 0;
					for (int i = 0; i < 10; i++)
						currentPrice += theDB.v_gamesInfo.at(i).price;//sumar precio del objeto a la cuenta
				}
				else
					done = true;
			} while (!done);
		}
	}
	return res;
}//CHECK

void Population::fillUP(Population * newe, Population * oldy,Individual &fath, Individual &moth, Individual &res, DB & games, float presupuesto )
{
	cout << "aqui iFill oldy:" << endl;
	printVecP(oldy);
	cout << endl << endl;
	
	cout << "aqui 1" << endl;
	bool incomplete = true;
	pair<Individual, Individual> currPair;//pareja de cruzados
	int ref = 1;
	Individual fat,mot,mFat, mMot;
	newe->v_thePop[0] = oldy->v_thePop[0];
	cout << "aqui 2 newe:" << endl;
	printVecP(newe);
	cout << endl << endl;
	while(ref <= 19) {

		cout << "aqui 3" << endl;

		//SELECTION
		try
		{
			fat = selection(*oldy);
		}
		catch (exception_ptr)
		{
			cout << "fat es null X.X" << endl;
		}
		try
		{
			mot = selection(*oldy);

		}
		catch (exception_ptr)
		{
			cout << "mot es null X.X" << endl;
		}
		



		
		cout << "aqui 4" << endl;

		//////CROSSING
		crossing(fat,mot,fath,moth);//leaves selected individuals in fath and moth

		cout << "aqui 5" << endl;

		//////MUTATION
		mutation(fath,games,res);//leaves mutated argument in res
		//mFat = res; 
		newe->v_thePop[ref] = res;//if it is not we add an individual to it
		ref++;



		mutation(moth, games, res);//leaves mutated argument in res
		//mMot = res;

		cout << "aqui 6" << endl;

		

		if ( (ref % 2 )== 0)//checks if population is complete
		{
			newe->v_thePop[ref] = res;//if it is not we add an individual to it
			ref++;
		}
		//cout << "aqui fWhile" << endl;

		//Population::printVecP(newe);
		//cout << endl<<endl;
	} 
	cout << "Done alle" << endl;

}



Individual Population::selection(Population & pop)//SELECCION
{
	float totalFitPOP = 0;
	float flag, sofar = 0;
	for (int i = 0; i < 20; i++)//obtiene total de fitness en la pop
	{
		totalFitPOP += pop.v_thePop[i].fitness;
	}
	for (int i = 0; i < 20; i++)//obtiene la probabilidad de cada individuo
	{
		pop.v_thePop[i].probability = pop.v_thePop[i].fitness / totalFitPOP;
	}
	flag = Smethods::random(0.0, 1.0);

	for (int i = 0; i < 20; i++)//elige segun la probabilidad
	{
		if (sofar > flag)
			return pop.v_thePop[i];
		sofar += pop.v_thePop[i].probability;
	}
}

void Population::printIndi(Individual & indi)//imprime el vector boolean del individuo
{
	for (int i = 0; i < 10; i++)
		cout<<" "<<indi.v_chromosome[i];
	cout << endl;
}
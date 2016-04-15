#include "Action.h"



Action::Action()
{
	//DB theDB;
	
	pair<Individual, Individual> paired;
	Individual ind;
	Individual *in1, *in2;
	Individual *res;
	in1 = new Individual; in2 = new Individual,res = new Individual;
	newe = 0;
	oldy = 0;
	temp = 0;
	pop1.initialize(theDB);//check is not this one
	oldy = &pop1;
	newe = &pop2;
	pop1.sort(pop1);

	int pass = 0,iterations;
	cout << "Give me the amount of iterations ";
	cin >> iterations;cout << endl;
	while (pass++ < iterations)
	{
		pop1.fillUP(newe,oldy,*in1,*in2,*res,theDB);
		pop1.sort(*newe);
		temp = oldy;//saves oldy address
		oldy = newe;//asigns to oldy newe address
		newe = temp;//assigns to newe oldy address saved in temp
	
	}




	//ind = pop1.v_thePop[0];
	//cout << endl << ind.fitness << " " << ind.probability << " " << ind.Tprice<<" "<<ind.v_chromosome[0] << " " << ind.v_chromosome[4] <<endl;

	//Population::fillUP(newe,oldy);
	//Population::printVecP(oldy);
	//Population::printVecP(newe);

	/*pop1.printIndi(pop1.v_thePop[0]);
	cout << endl;
	pop1.mutation(pop1.v_thePop[0],theDB,*res);
	pop1.printIndi(pop1.v_thePop[0]);
	cout << endl;*/

	////cout << endl;
	//pop1.printIndi(ind);
	
	
	
	/*paired = pop1.crossing(pop1.v_thePop[0], pop1.v_thePop[1],*in1,*in2);cout << endl;
	pop1.printIndi(pop1.v_thePop[0]);
	//pop1.printIndi(ind);
	pop1.printIndi(pop1.v_thePop[1]);
	cout << endl;cout << endl;
	paired = pop1.crossing(pop1.v_thePop[0], pop1.v_thePop[1],*in1,*in2);
	pop1.printIndi(paired.first);
	pop1.printIndi(paired.second);*/





	/*pop1.printVecP(pop1);
	cout << endl << endl;
	pop1.sort(pop1);
	pop1.printVecP(pop1);*/
	//cout << endl << pop1.evalFunc(pop1.v_thePop[0], theDB);
	/*for (int i = 0; i < 20; i++)
	{
		cout << endl << pop1.evalFunc(pop1.v_thePop[i], theDB);
	}*/
	//cout << endl << pop1.evalFunc(pop1.v_thePop[0], theDB);
	//cout<<endl<<pop1.fitGame(3,theDB);

	
}


Action::~Action()
{
}

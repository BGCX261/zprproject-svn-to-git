//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Algorithm.hpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#if !defined(_ALGORITHM_H)
#define _ALGORITHM_H

#include "../ToolsAndTypes/Thread.hpp"
#include "AlgorithmInterface.hpp"
#include "SpecimentCreator.hpp"
#include "Specimen.hpp"
#include "greater.hpp"
#include "Random.hpp"
#include "../ToolsAndTypes/AbstractSpecimen.hpp"
#include "../ToolsAndTypes/Task.hpp"
#include <list>
#include <iostream>
#include <vector>
#include <deque>


#include <boost/shared_ptr.hpp>


namespace Algorithm {
	using namespace ToolsAndTypes;
	class Algorithm :  public AlgorithmInterface {
	public:
		Algorithm();
		void run();

		Creator* getCreateSpecimenFun();

		std::list<AbstractSpecimen*> getSpeciments(); // blokowalna, std::list<AbstractSpeciment> list
		void putSpeciments(std::list<AbstractSpecimen*> list); // blokowalna, std::list<AbstractSpeciment> list
		
		void setTask(Task *task);
		void setNumberOfSpecimen(const int numer); // wielkosc populacji
		int getNumberOfSpeciment();  //zwraca wielkosc populacji
		void setInterval(const int interval);          //ilosc generacja
		int getInterval();
		void setSizeOfPutList(const int size);     //ilosc zwracanych elementow w lisice
		const int getSizeOfPutList();	 //ilosc zwracanych elementow w liscie
		
		int getProbabilityOfMutation();
		void setProbabilityOfMutation(const int probability);

		const unsigned getSizeOfDeque();
		void setSizeOfDeque(const unsigned size);


	private:
		int numberOfSpeciments;
		int sizeOfPutList;
		int interval;		//ilość generacji po jakich sprawdza kolejkę
		int probabilityOfMutation;
		unsigned sizeOfDeque;
		//Condition
		Condition emptyGetDeque;
		Condition fullPutDeque;


		int step;
		int stepBetweenIntervals;
		std::list<Specimen*> listOfSpeciments;	//lista obiektów
		boost::shared_ptr <AlgorithmInformation> algorithmInformation;
		boost::shared_ptr <SpecimentCreator> specimentCreator;
		std::auto_ptr<Random> aleatory;

		std::deque<std::list<AbstractSpecimen*> > putDeque;
		std::deque<std::list<AbstractSpecimen*> > getDeque;
		void putToGetDeque();
		void getFromPutDeque();
		void getNextGeneration();
		void orderCrossover(Specimen* first, Specimen* second);
		void mutation(Specimen* first);

		void sortSpeciments ();
		void createList();
		Specimen* createSpecimen();


	};
}

#endif  //_ALGORITHM_H

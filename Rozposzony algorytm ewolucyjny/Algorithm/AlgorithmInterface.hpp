//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AlgorithmInterface.hpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#if !defined(_ALGORITHMINTERFACE_H)
#define _ALGORITHMINTERFACE_H
#include "../ToolsAndTypes/Thread.hpp"
#include "../ToolsAndTypes/Task.hpp"
#include "SpecimentCreator.hpp"
#include "../ToolsAndTypes/AbstractSpecimen.hpp"
#include <list>
namespace Algorithm {
	using namespace ToolsAndTypes;
	class AlgorithmInterface : public ToolsAndTypes::Thread {
	public:

		
		virtual Creator * getCreateSpecimenFun()=0;

		virtual std::list<AbstractSpecimen*> getSpeciments()=0; // blokowalna, std::list<AbstractSpeciment> list
		virtual void putSpeciments(std::list<AbstractSpecimen*> list)=0; // blokowalna, std::list<AbstractSpeciment> list
		
		virtual void setTask(Task *task)=0;
		virtual void setNumberOfSpecimen(const int numer)=0; // wielkosc populacji
		virtual int getNumberOfSpeciment()=0;  //zwraca wielkosc populacji
		virtual void setInterval(const int interval)=0;          //ilosc generacja
		virtual int getInterval()=0;
		virtual void setSizeOfPutList(const int size)=0;     //ilosc zwracanych elementow w lisice
		virtual const int getSizeOfPutList()=0;	 //ilosc zwracanych elementow w lisice

		virtual int getProbabilityOfMutation()=0;
		virtual void setProbabilityOfMutation(const int probability)=0;

		virtual const unsigned getSizeOfDeque()=0;
		virtual void setSizeOfDeque(const unsigned size)=0;

	};
}

#endif  //_ALGORITHMINTERFACE_H

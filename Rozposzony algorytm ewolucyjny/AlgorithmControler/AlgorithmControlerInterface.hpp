//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AlgorithmControlerInterface.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_ALGORITHMCONTROLERINTERFACE_H)
#define _ALGORITHMCONTROLERINTERFACE_H
#include "../ToolsAndTypes/Thread.hpp"


namespace AlgorithmControler {
	class AlgorithmControlerInterface :  public ToolsAndTypes::Thread  {
	public:
		virtual void runAlgorithm()=0;
		virtual void interuptAlgorithm()=0;
		virtual void getArrayOfSpecimens()=0;
		//virtual void addNode()=0;
	
		//virtual void loadLibrary()=0;
	};


	
}

#endif  //_ALGORITHMCONTROLERINTERFACE_H

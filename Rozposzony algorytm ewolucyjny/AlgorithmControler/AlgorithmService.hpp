//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AlgorithmService.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_ALGORITHMSERVICE1_H)
#define _ALGORITHMSERVICE1_H
class NetIntService;
namespace AlgorithmControler
{
	class AlgorithmControler;
}

#include "../NetInterface/soapNetIntService.h"
#include "AlgorithmNetInterface.hpp"
#include "../ToolsAndTypes/Thread.hpp"
#include "../ToolsAndTypes/AbstractSpecimen.hpp"
#include "AlgorithmControler.hpp"

#include <memory>
#include <deque>
#include <list> 

namespace  AlgorithmControler{

	class AlgorithmService : public ToolsAndTypes::Thread {
	public:
		AlgorithmService(){}
		AlgorithmService(int port,AlgorithmControler* controler);
		bool putSpecimen(ToolsAndTypes::AbstractSpecimen* absSpecimen);
		std::list<ToolsAndTypes::AbstractSpecimen*> getSpecimenList();
		bool putSpecimenForChild(ToolsAndTypes::AbstractSpecimen* absSpecimen);
		ToolsAndTypes::AbstractSpecimen* getSpecimenForChild();
		void setConnections(Conections connections);
		void interupt();
		void runControler();
		void run();
		~AlgorithmService();

	static const int chgNumber=10;
	private:
		//AlgorithmControler *algorithmControler;
		std::auto_ptr<NetIntService> algControlerService;
		std::deque<ToolsAndTypes::AbstractSpecimen*> queue;
		std::deque<ToolsAndTypes::AbstractSpecimen*> childQueue;
		int port;
		static const int maxSize = 100;
		static const int maxChileQueue = 100;
		Condition fullChList;
		Condition emptyChList;
		Condition empty,full;
		AlgorithmControler* controler;
		
	};
}

#endif  //_ALGORITHMSERVICE_H

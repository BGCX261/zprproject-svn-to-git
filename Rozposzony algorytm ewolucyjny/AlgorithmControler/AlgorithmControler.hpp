//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AlgorithmControler.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_ALGORITHMCONTROLER_H)
#define _ALGORITHMCONTROLER_H
namespace AlgorithmControler {
class AlgorithmService;
}
namespace AlgorithmControler
{
	class AlgorithmControler;
	class TreeControler;
}


#include "AlgorithmControlerInterface.hpp"
#include "../ToolsAndTypes/Thread.hpp"
#include "../Algorithm/AlgorithmInterface.hpp"
#include "../Algorithm/Algorithm.hpp"
#include "AlgorithmNetInterface.hpp"
#include "Factory.hpp"
#include "History.hpp"
#include "AlgorithmService.hpp"
#include "AlgorithmProxy.hpp"
#include "Types.hpp"
#include <memory>
#include "boost/shared_ptr.hpp"
#include "Tree.hpp"





namespace AlgorithmControler {
	
	static int i;
	
class AlgorithmControler :public AlgorithmControlerInterface {
	public:
		enum Node {
			Parent,
			LChild,
			RChild,
			Root
		};

		AlgorithmControler();
		AlgorithmControler(int port,const Conections& conections);
		~AlgorithmControler();
	 
		
		virtual void run();

		virtual void runAlgorithm();
		virtual void interuptAlgorithm();
		virtual void getArrayOfSpecimens();
		virtual void setConnections(const Conections& conections);
		
		Algorithm::AlgorithmInterface *loadLibrary();
		bool isReady() const;

		

		private:
			bool ready;		
			boost::shared_ptr<Algorithm::AlgorithmInterface> algorithm; // zrobiæ sprytny
			
			std::auto_ptr<AlgorithmNetInterface> root;
			std::auto_ptr<AlgorithmNetInterface> parent;
			std::auto_ptr<AlgorithmNetInterface> lChild;
			std::auto_ptr<AlgorithmNetInterface> rChild;
			std::auto_ptr<AlgorithmService> algService;
			boost::shared_ptr<EndPoint> endPoint;
			std::auto_ptr<History> history;
			Factory *factory;
public:	const int ID;

			
			
	};

}

#include "TreeControler.hpp"
#endif  //_ALGORITHMCONTROLER_H

//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AlgorithmProxy.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_ALGORITHMPROXY_H)
#define _ALGORITHMPROXY_H

#include "AlgorithmNetInterface.hpp"
#include "../NetInterface/soapNetIntProxy.h"
#include "Types.hpp"
#include "Factory.hpp"
#include <memory>
#include <sstream>

namespace AlgorithmControler {
	class AlgorithmProxy : public AlgorithmNetInterface {
	public:
		AlgorithmProxy();
		~AlgorithmProxy(){};
	  void setEndPoint(const ToolsAndTypes::EndPoint& endPoint);
	  std::list<AbstractSpecimen*> exchangeSpecimens(std::list<AbstractSpecimen*>& specimentList);
	  Status getStatus();
	  void setParameter( ParameterChange parameterChange );
	  bool runAlgorithm();
	  void setConections( Conections conections );
	  void sendConectionsProblem(ConectionProblem );
	  void clean();
	  ToolsAndTypes::EndPoint getEndPoint() const;


	private:
		std::auto_ptr<NetIntProxy> soapControlerProxy;
		ToolsAndTypes::EndPoint endPoint;
	};
}

#endif  //_ALGORITHMPROXY_H

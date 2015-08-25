//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AlgorithmNetInterface.hpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#if !defined(_ALGORITHMNETINTERFACE_H)
#define _ALGORITHMNETINTERFACE_H

#include<iostream>
#include"Types.hpp"
#include<list>
#include"boost/shared_ptr.hpp"

namespace AlgorithmControler {
	using namespace ToolsAndTypes;
	class AlgorithmNetInterface {
	public:
	  virtual void setEndPoint(const EndPoint& endPoint)=0;
	  virtual std::list<AbstractSpecimen*> exchangeSpecimens(std::list<AbstractSpecimen*>& specimentList)=0;
	  virtual Status getStatus()=0;
	  virtual void setParameter( ParameterChange parameterChange )=0;
	  virtual bool runAlgorithm()=0;
	  virtual void setConections( Conections conections )=0;
	  virtual void sendConectionsProblem(ConectionProblem )=0;
	  virtual void clean()=0;
	  
	
	};
}

#endif  //_ALGORITHMNETINTERFACE_H

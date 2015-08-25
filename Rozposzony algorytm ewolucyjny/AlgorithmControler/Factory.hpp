//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : SpecimenFactory.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_SPECIMENFACTORY_H)
#define _SPECIMENFACTORY_H
#include "../ToolsAndTypes/Creator.hpp"
#include <iostream>
#include "boost/shared_ptr.hpp"
#include <map>
#include <sstream>
namespace AlgorithmControler {

class StringComp : public std::string
{
public:
	StringComp(){};
	StringComp(std::string string){str=string;}
	bool operator<( const StringComp& stringComp ) const
	{
		return str.compare(stringComp.str)<0;
		
	}
	std::string str;
};
	class Factory {
	public:
		static Factory& getInstance()
		{
			static Factory faktory;
			return faktory;
		}
		void addCreator(std::string name,ToolsAndTypes::Creator* creator);
		ToolsAndTypes::Object* create(const std::string& name, std::istringstream & ss);
	private:
		Factory();
		std::map < StringComp, boost::shared_ptr<ToolsAndTypes::Creator> > mapCreator;

	};
}

#endif  //_SPECIMENFACTORY_H

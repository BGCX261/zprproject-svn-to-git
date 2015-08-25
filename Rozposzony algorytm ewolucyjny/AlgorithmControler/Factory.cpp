//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : SpecimenFactory.cpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#include "Factory.hpp"



namespace AlgorithmControler {

	

	Factory::Factory()
	{}

	void Factory::addCreator(std::string name, ToolsAndTypes::Creator *creator)
	{
		StringComp stringComp;
		stringComp.str=name;
		mapCreator[stringComp]=boost::shared_ptr<ToolsAndTypes::Creator> (creator);
	}

	ToolsAndTypes::Object* Factory::create(const std::string &name, std::istringstream & ss)
	{
		return (*mapCreator[StringComp(name)])(ss);
	}
	
	
}

//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : History.cpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#include "History.hpp"

namespace AlgorithmControler {
	void History::addSpecimen(ToolsAndTypes::AbstractSpecimenPtr absSpecimen)
	{ if(!bestSpecimensSet.empty()){
		if(bestSpecimensSet.top()->getValue()<absSpecimen->getValue())
			bestSpecimensSet.push(absSpecimen);
		}
	else
		bestSpecimensSet.push(absSpecimen);
	}

ToolsAndTypes::AbstractSpecimenPtr History::getBestOne()
{
	return bestSpecimensSet.top();
}
	
}

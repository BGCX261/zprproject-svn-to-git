//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AbstractSpecimen.cpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#include "AbstractSpecimen.hpp"

namespace ToolsAndTypes {
	std::string AbstractSpecimen::getInfo() {
		return std::string();
	}
	
	int AbstractSpecimen::getValue() {
	
		return 0;
	}
	
	const int AbstractSpecimen::getGeneration() {
	return -1;
	}
	
	void AbstractSpecimen::setGeneration(const int z) {
	
	}

}

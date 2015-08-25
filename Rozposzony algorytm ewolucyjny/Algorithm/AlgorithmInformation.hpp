//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Algorithm.cpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//

#if !defined(_ALGORITMINFORMATION_H)
#define _ALGORITMINFORMATION_H

#include <iostream>
#include <vector>
#include <sstream>

namespace Algorithm {
class AlgorithmInformation
{
public:
	AlgorithmInformation (std::string &s);
	const int getDistance (int from, int to) const;
	const int getNumberOfCities ();


private:
	std::vector< std::vector <int> > distanceTable;
	int numberOfCities;
};
}

#endif  //_ALGORITMINFORMATION_H

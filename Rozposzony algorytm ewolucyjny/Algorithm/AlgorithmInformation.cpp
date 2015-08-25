//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Algorithm.cpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//

#include "AlgorithmInformation.hpp"


namespace Algorithm {

AlgorithmInformation::AlgorithmInformation(std::string &s)
{
	int temp;
	std::istringstream ss(s);
	ss>>temp;
	numberOfCities = temp;

	distanceTable.resize(numberOfCities-1);
	for (int i=0; i<numberOfCities-1; i++)
		distanceTable[i].resize(numberOfCities-i-1);

	for (int i=0; i<numberOfCities-1; i++)
		for (int j=0; j<numberOfCities-i-1; j++)
		{
				ss>>temp;
				distanceTable[i][j] = temp;
		}

}

const int AlgorithmInformation::getDistance (int from, int to) const
{
	if (from < to)
		return distanceTable[from][to-from-1];
	else if (from > to)
		return distanceTable[to][from-to-1];
	else
		return -1;
}

const int AlgorithmInformation::getNumberOfCities ()
{
	return numberOfCities;
}

}

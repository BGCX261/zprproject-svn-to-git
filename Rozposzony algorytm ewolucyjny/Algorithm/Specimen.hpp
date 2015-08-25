//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Specimen.hpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#if !defined(_SPECIMEN_H)
#define _SPECIMEN_H

#include "../ToolsAndTypes/AbstractSpecimen.hpp"
#include "AlgorithmInformation.hpp"
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <boost/shared_ptr.hpp>
#include <ctime>
#include <stdlib.h>

namespace Algorithm {
	class Specimen : public ToolsAndTypes::AbstractSpecimen {
	public:
		Specimen();
		Specimen(std::istringstream & ss);
		Specimen(std::istringstream & ss, boost::shared_ptr<AlgorithmInformation> z);
		Specimen(std::vector<int>* toPut, boost::shared_ptr<AlgorithmInformation> z);
		~Specimen(){};
		std::string getInfo();
		int getValue();
		const int getGeneration();
		void setGeneration(const int s) ;
		void serialize(std::ostringstream &os);

		void countValue();
		std::list<int> getTrack();
		std::vector<int>* getTrackForDead();	//wstawienie trasy
		void putTrack(std::vector<int>* toPut);
		void mutation(int first, int second);		//dodatkowe inwersje
		void crossing (std::list<int> to, int first, int second);
		void setAlgorithmInformation(boost::shared_ptr<AlgorithmInformation> toSet);


	protected:
			int value;
			int generation;		//wiek
			std::string info;
			std::vector<int> track;		//trasa 1-2-3 reprezentowana jest w bezposredniej
							//postaci tj track[0]=1, [1]=2, [3]=3, reprezentacja ścieżkowa

			boost::shared_ptr<AlgorithmInformation> algorithmInformation;
	};
}

#endif  //_SPECIMEN_H

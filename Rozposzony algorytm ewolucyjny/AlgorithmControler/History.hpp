//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : History.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_HISTORY_H)
#define _HISTORY_H

#include "../ToolsAndTypes/AbstractSpecimen.hpp"
#include <queue>
#include <vector>

class lesserSpecimen
{
public:
bool operator() (const ToolsAndTypes::AbstractSpecimenPtr& x,
		const ToolsAndTypes::AbstractSpecimenPtr& y) const
		{
		return x->getValue()<y->getValue();
		}

};

namespace AlgorithmControler {
	

	class History {
	public:
		History() : bestSpecimensSet(){}
		void addSpecimen(ToolsAndTypes::AbstractSpecimenPtr absSpecimen);
		ToolsAndTypes::AbstractSpecimenPtr getBestOne();
	private:
		std::priority_queue<ToolsAndTypes::AbstractSpecimenPtr,std::vector<ToolsAndTypes::AbstractSpecimenPtr>
		, lesserSpecimen> bestSpecimensSet;
	};
}

#endif  //_HISTORY_H

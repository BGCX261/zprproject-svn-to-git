/*
 * greater.hpp
 *
 *      Author: bogdan
 */

#if !defined(_GREATER_H)
#define _GREATER_H

#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "Specimen.hpp"

namespace std
{
using namespace Algorithm;
		template<>
		struct greater<Specimen*>
		{

			bool operator () (Specimen* lhs, Specimen* rhs ) const
			{
				return lhs->getValue() < rhs->getValue();
			}

		};
}

#endif //_GREATER_H

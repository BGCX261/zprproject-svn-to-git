//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Random.hpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//

#if !defined(_RANDOM_HPP_)
#define _RANDOM_HPP_

#include "boost/random/mersenne_twister.hpp"
#include "boost/random/uniform_int.hpp"
#include "boost/random/variate_generator.hpp"

#include <ctime>
#include <stdlib.h>

namespace Algorithm
{
	class Random		//generator liczb pseudolosowych z boost
	{
	public:
		Random();
		const int getRandom( int second );
		const int getRandom(const int first, const int second );

	private:
		boost::mt19937 gen;
	};
}

#endif /* _RANDOM_HPP_ */

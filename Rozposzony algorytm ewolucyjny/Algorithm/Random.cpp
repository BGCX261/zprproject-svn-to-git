#include "Random.hpp"

namespace Algorithm
{

Random::Random()
{

	gen.seed(static_cast<unsigned int>(std::time(0)));


}

const int Random::getRandom( int second )
{

	return this->getRandom(0, second-1);

}

const int Random::getRandom(const int first, const int second )
{

	boost::uniform_int<> dist(first, second);

	boost::variate_generator<boost::mt19937&, boost::uniform_int<> > die(gen, dist);

	return die();

}

}


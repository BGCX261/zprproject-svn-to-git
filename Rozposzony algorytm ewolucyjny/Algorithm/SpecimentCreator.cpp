/*
 * SpecimentCreator.cpp
 *
 *  Created on: 2010-04-30
 *      Author: Pawe�
 */

#include "SpecimentCreator.hpp"
#include <string>
#include "Specimen.hpp"
namespace Algorithm {
SpecimentCreator::SpecimentCreator() {

}

ToolsAndTypes::Object * SpecimentCreator::operator() (std::istringstream & ss)
{
	return new Specimen(ss);

}

SpecimentCreator::~SpecimentCreator()
{

}


}

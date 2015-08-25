/*
 * SpecimentCreator.h
 *
 *  Created on: 2010-04-30
 *      Author: Pawe�
 */


#ifndef SPECIMENTCREATOR_H_
#define SPECIMENTCREATOR_H_

#include "../ToolsAndTypes/AbstractSpecimen.hpp"
#include "../ToolsAndTypes/Creator.hpp"
#include "AlgorithmInformation.hpp"
#include <boost/shared_ptr.hpp>
#include <sstream>


namespace Algorithm {
	class SpecimentCreator : public ToolsAndTypes::Creator {
public:
	SpecimentCreator();

	ToolsAndTypes::Object * operator() (std::istringstream & ss);

	virtual ~SpecimentCreator();

};
}
#endif /* SPECIMENTCREATOR_H_ */

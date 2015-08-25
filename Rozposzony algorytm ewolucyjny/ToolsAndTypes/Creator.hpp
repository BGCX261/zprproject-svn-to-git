
#if !defined(_Creator_H)
#define _Creator_H
#include "AbstractSpecimen.hpp"
#include <sstream>


namespace ToolsAndTypes
{

	class Creator
	{
	public:
		virtual Object* operator() (std::istringstream & ss) = 0;
		
	};



}

#endif  //_Creator_H
#if !defined(_APP_TYPES_H)
#define _APP_TYPES_H

#include "../ToolsAndTypes/Serializable.hpp"
#include "../ToolsAndTypes/Creator.hpp"
#include "../ToolsAndTypes/Types.hpp"

#include <iostream>
#include <sstream>
#include <ostream>

namespace Application
{
class Status : public ToolsAndTypes::Serializable
{
public:
	Status(){};
	Status(std::istringstream & ss)
	{
		ss>>name;
		ss>>controlers;
	}
	void serialize(std::ostringstream &os)
	{
		os<<' ';
		if(!name.empty())
			os<<name;
		else
			os<<'0';
		os<<' ';
		os<<controlers;
	}

	std::string name;
	int controlers;
};




class StatusCreator : public ToolsAndTypes::Creator
{
public:
	ToolsAndTypes::Object* operator() (std::istringstream &is)
	{
		return new Status(is);
	}
};
}


#endif
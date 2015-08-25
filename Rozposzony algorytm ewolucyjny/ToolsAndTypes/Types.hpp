#if !defined(_APPTYPES_H)
#define _APPTYPES_H
#include <string>
#include <exception>
#include "Task.hpp"
namespace ToolsAndTypes
{


class ConnectionException : public std::exception
{
	int SOAP_ERROR;
public:
	ConnectionException() {}
	ConnectionException(const int& errNo ): SOAP_ERROR(errNo){}
	int getErrNo() const
	{
		return SOAP_ERROR;
	}
};


class EndPoint
{
public:
	EndPoint(){}
	EndPoint(std::string str) 
	{endPointStr=str;}
	std::string endPointStr;

};




}


#endif
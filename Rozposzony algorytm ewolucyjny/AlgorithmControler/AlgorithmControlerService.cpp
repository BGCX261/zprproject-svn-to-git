

#include "../NetInterface/soapNetIntService.h"
#include "../NetInterface/NetInt.nsmap"
#include "../ToolsAndTypes/AbstractSpecimen.hpp"



#include <iostream>
#include <sstream>

NetIntService::NetIntService(AlgorithmControler::AlgorithmService* service)
{
//AlgorithmControlerService();
NetIntService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	algService=service;
	modeSer=Control;
}


int NetIntService::setEndPoint(std::string endPoint, int &result)
{
	return SOAP_OK;
}

int NetIntService::exchangeSpecimens(std::string specimenList, std::string &result)
{

	ToolsAndTypes::AbstractSpecimen* absSpecimen;
	specimenList=specimenList;
	std::istringstream  ss(specimenList);
	std::ostringstream  os;
	char ch;
	ss.read(&ch,1);
	while(!ss.eof())
	{
		absSpecimen=static_cast<ToolsAndTypes::AbstractSpecimen*>(AlgorithmControler::Factory::getInstance().create("Specimen",ss));
		algService->putSpecimen(absSpecimen);
	}

	for(int i =0;i<algService->chgNumber;i++)
	{
		absSpecimen=algService->getSpecimenForChild();
		if(absSpecimen==NULL)
			break;
		absSpecimen->serialize(os);
		delete absSpecimen;
	}
		result=os.str();
	
		return SOAP_OK;
}

int NetIntService::getStatus(std::string &result)
{
	return SOAP_OK;
}

int NetIntService::setParameter(std::string parameterChange, int &result)
{
	return SOAP_OK;
}

int NetIntService::runAlgorithm(bool &result)
{
	result=true;
	std::cout<<"int AlgorithmControlerService::runAlgorithm(bool &result)"<<std::endl;
	algService->runControler();
	return SOAP_OK;
}

int NetIntService::sendConectionsProblem(std::string conectionProblem, int &result)
{
	return SOAP_OK;
}

 std::string ipToString(unsigned long x);


int NetIntService::setConections(std::string conections, int &result)
{
	std::istringstream is(conections);

	char ch;
	is.read(&ch,1);
	
	if(!is.eof())
	{
		result=0;
		AlgorithmControler::Conections *con;
		con=static_cast<AlgorithmControler::Conections*>
			(AlgorithmControler::Factory::getInstance().create("Connections",is));
		

		
		
		if(con->parent.endPointStr[0]=='l')
		{
			con->parent.endPointStr.erase(0,9);
			con->parent.endPointStr=ipToString(this->ip)+con->parent.endPointStr;
		}
		algService->setConnections(*con);
		delete con;
	}


	return SOAP_OK;
}


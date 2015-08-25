#include "AlgorithmService.hpp"
#include <iostream>

namespace AlgorithmControler {
	AlgorithmService::AlgorithmService(int port,AlgorithmControler* controler)
	{
		algControlerService=std::auto_ptr<NetIntService>(new NetIntService(this));
		this->controler=controler;
		this->port=port;
	}

	AlgorithmService::~AlgorithmService()
	{	
		join();
		algControlerService->destroy();	
	}

void AlgorithmService::interupt()
{
	Thread::interupt();
	algControlerService->soap_close_socket();
}

void AlgorithmService::runControler()
	{
		controler->start();
	}

void AlgorithmService::setConnections(Conections connections)
	{
		controler->setConnections(connections);
	
	}

void AlgorithmService::run()
	{
		
		//algControlerService->run(port);
		algControlerService->accept_timeout=1;
		algControlerService->bind(NULL,port,100);
int soapRet=SOAP_OK;
while(soapRet==SOAP_OK&&!isInterrupted())
	{
		if(soap_valid_socket(algControlerService->accept()))
			{
				//algControlerService->
				soapRet=algControlerService->serve();
				
				algControlerService->destroy();
			}
	}
		algControlerService->soap_stream_fault(std::cout);

	}
bool AlgorithmService::putSpecimen(ToolsAndTypes::AbstractSpecimen* absSpecimen) // dodac warunek
	{
		bool ret= false;
	enter();
	if(queue.size()>=maxSize) 
	{
		std::cout<<"Zapelnienie bufora "<<controler->ID<<std::endl;
		wait(full);
		int x=0;

	}

			queue.push_back(absSpecimen);
			ret=true;
	leave();
	
		return ret;
	}


std::list<ToolsAndTypes::AbstractSpecimen*> AlgorithmService::getSpecimenList()
{
	std::list<ToolsAndTypes::AbstractSpecimen*> absSpecimenList;
enter();	

while(!queue.empty())
{
	absSpecimenList.push_front(queue.front());
	queue.pop_front();
	
}
	signal(full);
	//signal(full);

leave();
return absSpecimenList;
}

ToolsAndTypes::AbstractSpecimen* AlgorithmService::getSpecimenForChild()
{
	ToolsAndTypes::AbstractSpecimen* absSpecimen=NULL;
	enter();
	if(!childQueue.empty())
	{
		absSpecimen=childQueue.front();
		childQueue.pop_front();
		signal(fullChList);
	}
	else
		absSpecimen=NULL;
	leave();
	return absSpecimen;
}

bool AlgorithmService::putSpecimenForChild(ToolsAndTypes::AbstractSpecimen *absSpecimen)
{
	bool ret=true;
	enter();
	if(childQueue.size()>=maxChileQueue) 
		ret=false;
	else
		childQueue.push_front(absSpecimen);
		
	leave();
	return ret;
}



	

	
}

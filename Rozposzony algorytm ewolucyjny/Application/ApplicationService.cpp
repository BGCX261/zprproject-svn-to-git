#include "ApplicationService.hpp"




namespace Application
{

	ApplicationService::ApplicationService(int port,Application *application)
	{
		this->application=application;
		
		this->appNetService=new NetIntService(this);
		this->port=port;
	}

	Status ApplicationService::getStatus()
	{
		Status status;
		status.name=application->getName();
		status.controlers = application->getNumerOfControlers();
		return status;
	}

	void ApplicationService::run()
	{
		appNetService->accept_timeout=1;
		SOAP_SOCKET socket=appNetService->bind(NULL,port,100);
		
	

		if(socket==SOAP_INVALID_SOCKET) interupt();
		int soapRet=SOAP_OK;
		while(soapRet==SOAP_OK&&!isInterrupted())
		{		
			if(soap_valid_socket(appNetService->accept()))
			{
				soapRet=appNetService->serve();
				appNetService->destroy();
			}
			
		}
	appNetService->soap_stream_fault(std::cout);
	}

	
	ApplicationService::~ApplicationService()
	{
	
		interupt();
		join();
		appNetService->destroy();
	
		
	}
		
		
	


	void ApplicationService::registerNode(ToolsAndTypes::EndPoint endPoint)
	{
		AppIntPtr appInt = AppIntPtr(new ApplicationProxy());
		appInt->setEndPoint(endPoint);
		application->registerNode(appInt);
	}
	
	ToolsAndTypes::EndPoint ApplicationService::newTask(ToolsAndTypes::Task task)
	{
		std::stringstream ss;
		 ss<<application->newTask(task);
		
		 return ToolsAndTypes::EndPoint(ss.str()); 
	}



}
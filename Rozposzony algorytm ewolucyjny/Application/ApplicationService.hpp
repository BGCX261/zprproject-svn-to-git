//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : ApplicationService.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_APPLICATIONSERVICE_H)
#define _APPLICATIONSERVICE_H

#include "ApplicationNetInterface.hpp"

#include "Application.hpp"
#include "../ToolsAndTypes/Thread.hpp"
#include "../NetInterface/soapNetIntService.h"
#include "Types.hpp"

#include <memory>
#include <deque>
#include <list> 

namespace Application {
	class Application;
	
	class ApplicationService : public ToolsAndTypes::Thread {
	public:
		ApplicationService(){}
		ApplicationService(int port,Application *application);
		void registerNode(ToolsAndTypes::EndPoint endPoint);
		ToolsAndTypes::EndPoint newTask(ToolsAndTypes::Task task);
		Status getStatus();
		

		void run();
		~ApplicationService();
	private:
		Application *application;
		NetIntService* appNetService;
		int port;
		
	};
}

#endif  //_APPLICATIONSERVICE_H

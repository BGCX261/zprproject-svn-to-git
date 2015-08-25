//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Application.cpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#include "Application.hpp"
#include "../ToolsAndTypes/Runnable.hpp"
#include "boost/thread.hpp"

#include "../NetInterface/soapNetIntProxy.h"

namespace Application {


	void Application::runTreeControler() 
	{
		treeControler->treeRun();	
	}

	std::string Application::getAppList() 
	{
		enter();
		std::stringstream ss;
		std::list<AppIntPtr>::iterator it;
		it=appList.begin();
		while(it!=appList.end())
		{
			Status status;

			status = (*it)->getStatus();

			ss<<status.name<<" "<<status.controlers<<std::endl;

			ss<<(*it)->getEndPoint().endPointStr<<std::endl;
			it++;
		}
		leave();
		return ss.str();
	}

	int Application::getNumerOfControlers()const
	{
		return (int )algList.size();
	}

	Application::Application(const int& aPort,const std::string &aname) : port(aPort),name(aname),controlerPort(aPort)
	{
		appService = std::auto_ptr<ApplicationService>(new ApplicationService(aPort,this));
		appService->start();	

		AlgorithmControler::Factory::getInstance().addCreator("Connections",new AlgorithmControler::ConectionsCreator());
		AlgorithmControler::Factory::getInstance().addCreator("Status",new StatusCreator());
	}

	Application::Application() : port(4680), appCounter(0)
	{
		appService = std::auto_ptr<ApplicationService>(new ApplicationService(4961,this));
		appService->start();	

		AlgorithmControler::Factory::getInstance().addCreator("Connections",new AlgorithmControler::ConectionsCreator());
		AlgorithmControler::Factory::getInstance().addCreator("Status",new AlgorithmControler::StatusCreator());
	
	}

	Application::~Application()
	{
		
	}
	
	void Application::createTreeControler() 
	{
		AlgorithmControler::Conections conections;
		conections.parent.endPointStr="localhost:4270";
		treeControler = new  AlgorithmControler::TreeControler(4270, conections);
		//thread= static_cast<ToolsAndTypes::Thread*> (algorithmControler);
	}

	void Application::registerNode(AppIntPtr appInt)
	{
		enter();
		std::cout<<"Zarejestrowano polaczenie z: "<<appInt->getEndPoint().endPointStr<<std::endl;
			appList.push_front(appInt);
		leave();
	}

	bool Application::setConection(ToolsAndTypes::EndPoint dest)
	{
		AppIntPtr appInt = AppIntPtr(new ApplicationProxy());
		appInt->setEndPoint(dest);
		
		std::stringstream ss;
		ss<<port;
		ToolsAndTypes::EndPoint myAddr(ss.str());
		if(appInt->registerNode(myAddr))
		{
			appList.push_front(appInt);
			return true;
		}
		return false;
	}

	int Application::newTask(ToolsAndTypes::Task)
	{
		int ret;
		enter();
		AlgorithmControler::Conections conections;	
		algList.push_front(AlgIntPtr(new AlgorithmControler::AlgorithmControler(++controlerPort,conections)));
		 ret=controlerPort;
		leave();
		std::cout<<"Utowrzylem now� instacje algorytmu na portcie: "<<ret<<std::endl;
		return ret;
	}

	std::string Application::getNodeList()
	{
		return std::string();
	}

	void Application::getTreeNode(const std::string& name)
	{
	enter();
		AlgorithmControler::TreeNodePtr treeNode;
		ToolsAndTypes::EndPoint endPoint;
		if(appList.empty()) return;

		appCounter%=appList.size();
		std::list<AppIntPtr>::iterator it;
		it=appList.begin();
		for(int i=0;i<appList.size();i++)
		{
			if ((*it)->getStatus().name==name) 
				break;
			it++;
		}
		if(it==appList.end())
		{
			leave();
			return;
		}
			endPoint=(*it)->newTask(ToolsAndTypes::Task());
		
		treeNode = AlgorithmControler::TreeNodePtr(new AlgorithmControler::TreeNode());
		treeNode->setEndPoint(endPoint);
		treeControler->addNode(treeNode);
		appCounter++;
	leave();
	}
void Application::setName(const std::string& aname)
{
	enter();
		name = aname;
	leave();
}

std::string Application::getName()
{
	std::string ret;
	enter();
	ret = name;
	leave();
	return ret;
}
	
}


int main()
{
	
	Application::View view;
	view.start();



		


return 0;
}


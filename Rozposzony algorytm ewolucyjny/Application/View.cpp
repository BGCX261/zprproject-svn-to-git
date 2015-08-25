#include "View.hpp"

namespace Application {
View::View(void)
{
}

View::View(AppPtr app):application(app)
{

}

View::~View(void)
{
}

void View::treeControler()
{
		application->createTreeControler();
		std::string command;

		while(true)
		{
			std::cin>>command;

			if(command=="con")
			{
				std::cout<<"Aktualne polacznia to: "<<std::endl;
				std::cout<<application->getAppList();
				continue;
			}
			if(command=="addNode")
			{
				std::string name;
				std::cin>>name;
				application->getTreeNode(name);
			}
			if(command=="showNodes")
			{
				std::cout<<"Gotowe wezly obliczen"<<std::endl;
				std::cout<<application->getNodeList();
			}

			if(command=="run")
			{
				std::cout<<"Start"<<std::endl;
				application->runTreeControler();
			}


		
		}
}

void View::slave()
{
	    std::cout<<"Podaj z addres i port serwera z ktorym mam sie polaczyc: "<<std::endl;
		ToolsAndTypes::EndPoint dest;
		std::cin>>dest.endPointStr;
		application->setConection(dest);
		char ch;
		std::cin>>ch;
}

void View::start()
{
	int port;
	std::string name;
	std::cout<<"Witaj uzytkowoniku"<<std::endl;
	std::cout<<"Podaj nazwe dla wezla"<<std::endl;
	
	std::cin>>name;

	std::cout<<"Podaj port na ktorym ma rezydowac serwer aplikacji: ";
	std::cin>>port;
	application=AppPtr(new Application(port,name));

	char ch;
	std::cout<<"Czy uruchomic kontroler drzewa oblicze� t/n ??"<<std::endl;
	std::cin>>ch;

	if(ch=='t')
		treeControler();
	else
		slave();
 

	system("pause");
}



}

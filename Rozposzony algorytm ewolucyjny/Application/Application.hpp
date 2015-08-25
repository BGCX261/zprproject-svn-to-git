//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Application.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_APPLICATION_H)
#define _APPLICATION_H
namespace AlgorithmControler
{
	class AlgorithmControler;
	class TreeControler;
	class TreeNode;
}
#include "ApplicationNetInterface.hpp"
#include "../AlgorithmControler/AlgorithmControlerInterface.hpp"
#include "../AlgorithmControler/AlgorithmControler.hpp"


#include "ApplicationService.hpp"
#include <memory>
#include <list>
#include "boost/shared_ptr.hpp"
#include "ApplicationProxy.hpp"
#include "../AlgorithmControler/Types.hpp"
#include "../ToolsAndTypes/Types.hpp"
#include "../AlgorithmControler/Tree.hpp"
#include "View.hpp"
namespace Application {
class Application;
	typedef boost::shared_ptr<ApplicationNetInt> AppIntPtr;
	typedef boost::shared_ptr<AlgorithmControler::AlgorithmControlerInterface> AlgIntPtr;
	
class ApplicationService;	
class Application : public ToolsAndTypes::Monitor
{
	public:
		Application();
		Application(const int& aPort, const std::string& aName );
		~Application();
		void runTreeControler();
		void createTreeControler();
		ApplicationNetInt *applicationProxy;
		bool setConection(ToolsAndTypes::EndPoint dest);
		void registerNode(AppIntPtr appInt);
		void getTreeNode(const std::string& name);
		std::string getAppList();
		std::string getNodeList();
		int newTask(ToolsAndTypes::Task);
		void setName(const std::string & name);
		std::string getName();
		int getNumerOfControlers() const;
		
	private:
		int appCounter;
		AlgorithmControler::TreeControler *treeControler;
		std::list<AlgorithmControler::TreeNodePtr> treeNodeList;
		std::list<AlgIntPtr> algList;
		std::list<AppIntPtr> appList;
		//View *view;
		std::auto_ptr<ApplicationService> appService;
		int port;
		int controlerPort;
		std::string name;
	};
}

#endif  //_APPLICATION_H

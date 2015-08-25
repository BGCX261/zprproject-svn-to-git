//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AlgorithmControler.cpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#include "AlgorithmControler.hpp"
#include <iostream>
#include <sstream>
#include "../NetInterface/soapH.h"

namespace AlgorithmControler {
	using namespace ToolsAndTypes;
	

	bool AlgorithmControler::isReady() const
	{
		return ready;
	}

	AlgorithmControler::~AlgorithmControler()
		{
		interupt();
		join();
			
		}
		
	void AlgorithmControler::run() {

		bool flaga=false;
		
		std::cout<<	"void AlgorithmControler::run()"<<std::endl; 
		runAlgorithm();
		

		
		while( true )
		{
			
			std::list<AbstractSpecimen*> specimenList;
		    std::list<AbstractSpecimen*> sendList,recvList;

			specimenList=algorithm->getSpeciments();
			
			
		
		int emount;
		if(lChild.get()!=NULL||rChild.get()!=NULL)
			emount=specimenList.size()/3;
		else
			emount=specimenList.size();

		if(parent.get()==NULL) 
			emount=0;
			for(int i=0;i<emount;i++)
			{
				sendList.push_front(specimenList.front());
				specimenList.pop_front();
			}
        
			while(!specimenList.empty())
			{
				if(!algService->putSpecimenForChild(specimenList.front()))
				{
					delete specimenList.front();
				}
				
				specimenList.pop_front();
			}
		

			std::list<AbstractSpecimen *> recvFromChild;
			recvFromChild=algService->getSpecimenList();
			
			enter();
				if(parent.get()!=NULL)
				{
				
					try
					{
						if(!isInterrupted())
						recvList=parent->exchangeSpecimens(sendList);
					}
					catch (ToolsAndTypes::ConnectionException &conExp)
					{
						interupt();
					}
				}
				else
				{
					if(!recvFromChild.empty())
					{
						///history->addSpecimen(AbstractSpecimenPtr(sendList.front()));
						//recvFromChild.pop_front();
					}
					
				}
			leave();
			
			this;
			while(!recvFromChild.empty())
			{
				recvList.push_front(recvFromChild.front());
				recvFromChild.pop_front();
			}
				algorithm->putSpeciments(recvList);

				if(parent.get()!=NULL)
					parent->clean();
	
		if(isInterrupted())
		{
			algService->interupt();
			if(algService->isInterrupted())
			{
				algService =std::auto_ptr<AlgorithmService>();
				break;
			}
		}

		}
		algorithm->interupt();
		algorithm->join();
		
	}
	
	AlgorithmControler::AlgorithmControler():
		ID(i)
	{
		
			
	}

	

	AlgorithmControler::AlgorithmControler(int port,const Conections& conections)
		: ID(i)
	{
		i++;
		algorithm = boost::shared_ptr<Algorithm::AlgorithmInterface>(loadLibrary());
		factory = &Factory::getInstance();
		factory->addCreator("Specimen",algorithm->getCreateSpecimenFun());	
		
		algService= std::auto_ptr<AlgorithmService>(new AlgorithmService(port,this));	
		parent=std::auto_ptr<AlgorithmNetInterface>(new AlgorithmProxy());

		//std::stringstream ss;
		//ss<<"localhost:"<<port;
	//parent->setEndPoint(ss.str());

		setConnections(conections);

		history = std::auto_ptr<History>(new History());

	algService->start();

		
	}

	void AlgorithmControler::setConnections(const Conections& conections)
	{
		enter();
		
		if(parent.get()!=NULL)
			parent = std::auto_ptr<AlgorithmNetInterface>();

		if(!conections.root.endPointStr.empty())
		{
			root=std::auto_ptr<AlgorithmNetInterface>(new AlgorithmProxy());
			root->setEndPoint(conections.root);
		}
		if(!conections.parent.endPointStr.empty())
		{
			std::string str = conections.parent.endPointStr;
			parent=std::auto_ptr<AlgorithmNetInterface>(new AlgorithmProxy());
			parent->setEndPoint(conections.parent);
		}
		if(!conections.lChild.endPointStr.empty())
		{
			lChild=std::auto_ptr<AlgorithmNetInterface>(new AlgorithmProxy());
			lChild->setEndPoint(conections.lChild);
		}
		if(!conections.rChild.endPointStr.empty())
		{
			rChild=std::auto_ptr<AlgorithmNetInterface>(new AlgorithmProxy());	
			rChild->setEndPoint(conections.rChild);
		}
		leave();
	}

	void AlgorithmControler::runAlgorithm()
	{
			
			ToolsAndTypes::Task* task=new ToolsAndTypes::Task();
			task->readFromFile();
			algorithm->setTask(task);
			algorithm->start();
			
	}

	void AlgorithmControler::getArrayOfSpecimens()
	{

	}

	Algorithm::AlgorithmInterface * AlgorithmControler::loadLibrary()
	{
		
		return new Algorithm::Algorithm;
	}

	void AlgorithmControler::interuptAlgorithm()
	{
		interupt();
		join();

	}

	

}

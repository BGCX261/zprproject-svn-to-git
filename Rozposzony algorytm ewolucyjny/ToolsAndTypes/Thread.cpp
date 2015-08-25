//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Thread.cpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#include "Thread.hpp"


namespace ToolsAndTypes {
void myThread(Runnable* run)
	{
	run->run();
	}
	void Thread::start()
	{
		if(running) return;
		running=true;
		interrupt=false;
		Runnable* run = static_cast<Runnable*> (this);
		ptrThread=std::auto_ptr<boost::thread>(new boost::thread(myThread,run));
	
	}
	void Thread::join()
	{
		if(ptrThread.get()!=NULL)
			ptrThread->join();
	}

	bool Thread::isInterrupted() {
		bool ret;
		//enter();
		ret = interrupt;
		//leave();
		return ret;
	}
	
	void Thread::interupt() {
		enter();
		interrupt=true;
		leave();
	}
	
}

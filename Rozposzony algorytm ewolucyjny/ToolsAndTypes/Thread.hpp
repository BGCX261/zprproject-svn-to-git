//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Thread.hpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#if !defined(_THREAD_H)
#define _THREAD_H

#include "Runnable.hpp"
#include "Monitor.hpp"
#include "boost/thread.hpp"
#include <memory>



namespace ToolsAndTypes {
	class Thread : public Runnable, public Monitor {
	public:
		Thread(): running(false) {};
		virtual void run() = 0;
		virtual void start();
		virtual void join();
		bool isInterrupted();
		void interupt();
		

	private:
		bool interrupt;
		std::auto_ptr<boost::thread> ptrThread;
		bool running;
		
	};
}

#endif  //_THREAD_H

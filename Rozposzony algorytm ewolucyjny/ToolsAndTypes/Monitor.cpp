//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Monitor.cpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#include "Monitor.hpp"

namespace ToolsAndTypes {


	Monitor::Monitor()
	{
		//lock = boost::mutex::scoped_lock(mutex);
	}

	void Monitor::wait(Condition&  condition) {
	condition.wait(mutex);
	}
	
	void Monitor::signal(Condition&  condition) {
		condition.notify_one();
	}
	
	void Monitor::enter() {
		
		
		mutex.lock();
	
	}
	
	void Monitor::leave() {
		mutex.unlock();
	
	}
	
	
	
	
}

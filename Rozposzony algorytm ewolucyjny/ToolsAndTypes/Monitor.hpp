//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Monitor.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_MONITOR_H)
#define _MONITOR_H

#include "boost/thread/mutex.hpp"
#include "boost/thread/condition.hpp"

namespace ToolsAndTypes {
	class Monitor {
	public:
		Monitor();
		typedef boost::condition Condition;
		void wait(Condition& condition);
		void signal(Condition& condition);
		void enter();
		void leave();

	private:
		boost::mutex mutex;
		boost::mutex::scoped_lock lock;
		Condition mutal;
	};
}

#endif  //_MONITOR_H

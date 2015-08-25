//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : View.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_VIEW_H)
#define _VIEW_H
#include "Application.hpp"

namespace Application {
	class Application;
	typedef boost::shared_ptr<Application> AppPtr;
	class View {
		public:
	View(void);
	View(AppPtr app);
	void start();
	void treeControler();
	void slave();
	~View(void);

private:
	AppPtr application;
	};
}

#endif  //_VIEW_H

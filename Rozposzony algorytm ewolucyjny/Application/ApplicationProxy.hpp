//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : ApplicationProxy.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_APPLICATIONPROXY_H)
#define _APPLICATIONPROXY_H

#include "ApplicationNetInterface.hpp"
#include "../NetInterface/soapNetIntProxy.h"
#include "../AlgorithmControler/Factory.hpp"
#include <memory>
namespace Application {
	class ApplicationProxy : public ApplicationNetInt {
	public:
		ApplicationProxy();
		bool registerNode(const ToolsAndTypes::EndPoint& endPoint);
		void setEndPoint(const ToolsAndTypes::EndPoint& endPoint);
		ToolsAndTypes::EndPoint getEndPoint()const;
		ToolsAndTypes::EndPoint newTask(const ToolsAndTypes::Task& task);
		Status getStatus();
		~ApplicationProxy();
	private:
		std::auto_ptr<NetIntProxy> appNetProxy;
		ToolsAndTypes::EndPoint endPoint;

	};
}

#endif  //_APPLICATIONPROXY_H

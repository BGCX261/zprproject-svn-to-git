//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : ApplicationNetInterface.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_APPLICATIONNETINTERFACE_H)
#define _APPLICATIONNETINTERFACE_H
#include "../ToolsAndTypes/Types.hpp"
#include "Types.hpp"

namespace Application {
	class ApplicationNetInt {
	public:
		virtual bool registerNode(const ToolsAndTypes::EndPoint& endPoint)=0;
		virtual void setEndPoint(const ToolsAndTypes::EndPoint& endPoint)=0;
		virtual ToolsAndTypes::EndPoint getEndPoint() const =0;
		virtual ToolsAndTypes::EndPoint newTask(const ToolsAndTypes::Task& task)=0;
		virtual Status getStatus()=0;
	};
}

#endif  //_APPLICATIONNETINTERFACE_H

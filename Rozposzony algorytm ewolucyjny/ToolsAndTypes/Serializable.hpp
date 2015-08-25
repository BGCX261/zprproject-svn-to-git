//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Serializable.hpp
//  @ Author : Pawe³ Marchewka, Bogdan Jezierski
//
//


#if !defined(_SERIALIZABLE_H)
#define _SERIALIZABLE_H
#include <iostream>
#include <ostream>
#include "Object.hpp"
namespace ToolsAndTypes {
	class Serializable : public Object {
	public:
		virtual void serialize(std::ostringstream &os)=0;
	};
}

#endif  //_SERIALIZABLE_H

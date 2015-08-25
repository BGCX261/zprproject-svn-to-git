//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : AbstractSpecimen.hpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#if !defined(_ABSTRACTSPECIMEN_H)
#define _ABSTRACTSPECIMEN_H

#include "Serializable.hpp"
#include "boost/shared_ptr.hpp"


namespace ToolsAndTypes {
	class AbstractSpecimen : public Serializable {
	public:
		virtual ~AbstractSpecimen(){};
		virtual std::string getInfo()=0;	//trasa
		virtual int getValue()=0;
		virtual const int getGeneration()=0;	//int wiek
		virtual void setGeneration(const int s) =0;


	};
	typedef boost::shared_ptr<AbstractSpecimen> AbstractSpecimenPtr;
}

#endif  //_ABSTRACTSPECIMEN_H

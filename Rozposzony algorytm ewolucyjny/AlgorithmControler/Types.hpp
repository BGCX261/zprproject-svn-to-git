#if !defined(_ALGORITHMCONTROLERTYPES_H)
#define _ALGORITHMCONTROLERTYPES_H

#include "../ToolsAndTypes/Serializable.hpp"
#include "../ToolsAndTypes/Creator.hpp"
#include "../ToolsAndTypes/Types.hpp"
#include "boost/shared_ptr.hpp"
#include <iostream>
#include <sstream>
#include <ostream>


namespace AlgorithmControler
{
class TreeNode;
typedef boost::shared_ptr<TreeNode> TreeNodePtr;
}

namespace AlgorithmControler {
class ToolsAndTypes::EndPoint;

class ParameterChange : public ToolsAndTypes::Serializable
{
public:

	ParameterChange(std::istringstream & ss);
	void serialize(std::ostringstream &os);
	enum Parameter { Interval, RegisterEndpoint };
	void setValue(int x);
	void setValue(std::string x);
	int getIntValue();
	std::string getStringValue();
	
private:
	std::string value;
	int x;
	
};
class ParameterChangeCreator : public ToolsAndTypes::Creator
{
public: 
		ToolsAndTypes::Object* operator() (std::istringstream & ss)
		{
			return new ParameterChange(ss);
		}
};





class Conections : public ToolsAndTypes::Serializable
{
public:
	Conections() {}
	Conections(std::istringstream & ss)
	{
	ss>>root.endPointStr;
	if(root.endPointStr[0]=='0') root.endPointStr.clear();
	ss>>parent.endPointStr;
	if(parent.endPointStr[0]=='0') parent.endPointStr.clear();
	ss>>lChild.endPointStr;
	if(lChild.endPointStr[0]=='0') lChild.endPointStr.clear();
	ss>>rChild.endPointStr;
	if(rChild.endPointStr[0]=='0') rChild.endPointStr.clear();
	}
	void serialize(std::ostringstream &os)
	{
	os<<' ';
	if(!root.endPointStr.empty())
		os<<root.endPointStr;
	else
		os<<"0";

	os<<' ';
	if(!parent.endPointStr.empty())
		os<<parent.endPointStr;
	else
		os<<'0';
	os<<' ';
	if(!lChild.endPointStr.empty())
		os<<lChild.endPointStr;
	else
		os<<'0';
	os<<' ';
	if(!rChild.endPointStr.empty())
		os<<rChild.endPointStr;
	else
		os<<'0';
	}
	ToolsAndTypes::EndPoint root;
	ToolsAndTypes::EndPoint parent;
	ToolsAndTypes::EndPoint lChild;
	ToolsAndTypes::EndPoint rChild;
};




class ConectionsCreator : public ToolsAndTypes::Creator
{
public: 
		ToolsAndTypes::Object* operator() (std::istringstream & ss)
		{
			return new Conections(ss);
		}
};

class Status : public ToolsAndTypes::Serializable
{
public:
	Status(){};
	Status(std::istringstream & ss){};
	void serialize(std::ostringstream &os){}
};

class StatusCreator : public ToolsAndTypes::Creator
{
public: 
		ToolsAndTypes::Object* operator() (std::istringstream & ss)
		{
			return new Status(ss);
		}
};

class ConectionProblem : public ToolsAndTypes::Serializable
{
public:
	void serialize(std::ostringstream &os);

};




}


#endif
#include "AlgorithmProxy.hpp"


namespace AlgorithmControler
{

	AlgorithmProxy::AlgorithmProxy()
	{
		soapControlerProxy = std::auto_ptr<NetIntProxy>(new NetIntProxy()); 
	}

	void AlgorithmProxy::sendConectionsProblem(AlgorithmControler::ConectionProblem)
	{
	}

	void AlgorithmProxy::setEndPoint(const ToolsAndTypes::EndPoint& endPoint)
	{

		this->endPoint=endPoint;
		soapControlerProxy->soap_endpoint=this->endPoint.endPointStr.c_str();
	}


	void AlgorithmProxy::setConections(AlgorithmControler::Conections conections)
	{
		std::ostringstream os;
		conections.serialize(os);
		int ret;
		int r;
		r=soapControlerProxy->setConections(os.str(),ret);

	}

	ToolsAndTypes::EndPoint AlgorithmProxy::getEndPoint() const
	{
		return ToolsAndTypes::EndPoint(endPoint);
	}

	void AlgorithmProxy::setParameter(AlgorithmControler::ParameterChange parameterChange)
	{
	}

	Status AlgorithmProxy::getStatus()
	{
		return Status();
	}

	bool AlgorithmProxy::runAlgorithm()
	{
		bool result;
		int soapResult;
		soapResult=soapControlerProxy->runAlgorithm(result);
		SOAP_OK;
		return false;
	}

	std::list<AbstractSpecimen*> AlgorithmProxy::exchangeSpecimens(std::list<AbstractSpecimen*>& specimentList)
	{
		std::string send,recv;
		std::ostringstream os;
		std::list<AbstractSpecimen*> returnList;
		ToolsAndTypes::AbstractSpecimen* absSpecimen;
		while(!specimentList.empty())
		{
			absSpecimen = specimentList.front();
			specimentList.pop_front();
			absSpecimen->serialize(os);
			delete absSpecimen;
		}
		send=os.str();
		int ret;
		ret=soapControlerProxy->exchangeSpecimens(send,recv);
		soapControlerProxy->destroy();
		if(ret!=SOAP_OK)
			throw ToolsAndTypes::ConnectionException(ret);
		try
		{
		std::istringstream  ss(recv);
			char ch;
	ss.read(&ch,1);
			while(!ss.eof())
				returnList.push_front(static_cast<AbstractSpecimen*> (Factory::getInstance().create("Specimen",ss)));
		}
		catch(...)
		{}
	
		return returnList;
		
	}

	void AlgorithmProxy::clean()
	{
		soapControlerProxy->destroy();
	}

}
#include "ApplicationProxy.hpp"


namespace Application
{
	ApplicationProxy::ApplicationProxy()
	{
		appNetProxy = std::auto_ptr<NetIntProxy> (new NetIntProxy);

	}

	ApplicationProxy::~ApplicationProxy()
	{
		

	}
	void ApplicationProxy::setEndPoint(const ToolsAndTypes::EndPoint& endPoint)
	{
		this->endPoint=endPoint;
		appNetProxy->soap_endpoint=this->endPoint.endPointStr.c_str();
	}

	bool ApplicationProxy::registerNode(const ToolsAndTypes::EndPoint& endPoint)
	{
		int result;
		if(appNetProxy->registNode(endPoint.endPointStr,result)==SOAP_OK)
			return true;
		
		return false;
	}
	ToolsAndTypes::EndPoint ApplicationProxy::getEndPoint() const
	{
		return endPoint;
	}

	ToolsAndTypes::EndPoint ApplicationProxy::newTask(const ToolsAndTypes::Task& task)
	{
		std::string result;
		
		if(appNetProxy->newTask(std::string(), result)==SOAP_OK )
		{
			int i=0;
			std::string tmp;
			while(i<endPoint.endPointStr.size())
			{
				char ch;
				ch=endPoint.endPointStr[i++];
				tmp+=ch;
				if(ch==':') break;
				
			}
			result=tmp+result;
			return ToolsAndTypes::EndPoint(result);
		}
		else
			return ToolsAndTypes::EndPoint();
	}

	Status ApplicationProxy::getStatus()
	{
		Status *status;
		Status ret;
		std::string result;
		appNetProxy->getAppStatus(result);

		std::istringstream is(result);

		status=static_cast<Status*> (AlgorithmControler::Factory::getInstance().create("Status",is));
		ret=*status;
		delete status;
		return ret;
	}

}
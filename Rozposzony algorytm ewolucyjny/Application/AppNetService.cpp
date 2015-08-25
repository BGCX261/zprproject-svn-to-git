#include "../NetInterface/soapNetIntService.h"

//#include "../NetInterface/NetInt.nsmap"




 
 NetIntService::NetIntService(Application::ApplicationService * appService)
	{
		NetIntService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
		this->appService=appService;
		modeSer=App;
	}
	
 std::string ipToString(unsigned long x)
 {
	 int a = (x>>24) & 0xff;
	 int b = (x>>16) & 0xff;
	 int c = (x>>8) & 0xff;
	 int d = x & 0xff;
	 std::stringstream ss;
	 ss<<a<<"."<<b<<"."<<c<<"."<<d;
	 return ss.str();
 }

	int NetIntService::registNode(std::string endPoint, int &result)
	{
		this;
		
		ToolsAndTypes::EndPoint retPoint;
		endPoint=ipToString(this->ip)+":"+endPoint;
		retPoint.endPointStr=endPoint;
		appService->registerNode(endPoint);	
		return SOAP_OK;
	}
	
	/// Web service operation 'unRegistNode' (returns error code or SOAP_OK)
	int NetIntService::unRegistNode(std::string endPoint, int &result)
	{
		return SOAP_OK;
	}


	/// Web service operation 'getSpecimens' (returns error code or SOAP_OK)
	int NetIntService::getSpecimens(std::string &result)
	{
		return SOAP_OK;
	}

	/// Web service operation 'getStatus' (returns error code or SOAP_OK)
	int NetIntService::getAppStatus(std::string &result)
	{
		std::ostringstream os;
		appService->getStatus().serialize(os);
		result=os.str();

		return SOAP_OK;
	}

	/// Web service operation 'setParameter' (returns error code or SOAP_OK)
	int NetIntService::setAppParameter(std::string parameterChange, int &result)
	{
		return SOAP_OK;
	}

	/// Web service operation 'newTask' (returns error code or SOAP_OK)
	int NetIntService::newTask(std::string task, std::string &result)
	{
		ToolsAndTypes::EndPoint ret;
		ret=appService->newTask(ToolsAndTypes::Task());
		result=ret.endPointStr;
		return SOAP_OK;
	}

	/// Web service operation 'getConnectedNodes' (returns error code or SOAP_OK)
	int NetIntService::getConnectedNodes(std::string &conections)
	{
		return SOAP_OK;
	}

	/// Web service operation 'sendMessage' (returns error code or SOAP_OK)
	int NetIntService::sendMessage(std::string message, int &result)
	{
		return SOAP_OK;
	}



//gsoap ns service name:	calc Simple calculator service
//gsoap ns service style:	rpc
//gsoap ns service encoding:	encoded

//gsoap ns schema namespace:	urn:calc

int ns__setEndPoint(std::string endPoint);
int ns__exchangeSpecimens(std::string specimentList,std::string & result);
int ns__getStatus(std::string & result);
int ns__setParameter( std::string parameterChange );
int ns__runAlgorithm(bool & result);
int ns__setConections( std::string conections );
int ns__sendConectionsProblem(std::string conectionProblem );
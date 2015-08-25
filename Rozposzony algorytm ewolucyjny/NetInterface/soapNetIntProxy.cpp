/* soapNetIntProxy.cpp
   Generated by gSOAP 2.7.15 from NetInteface.h
   Copyright(C) 2000-2009, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#include "soapNetIntProxy.h"

NetIntProxy::NetIntProxy()
{	NetIntProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

NetIntProxy::NetIntProxy(const struct soap &_soap) :soap(_soap)
{ }

NetIntProxy::NetIntProxy(soap_mode iomode)
{	NetIntProxy_init(iomode, iomode);
}

NetIntProxy::NetIntProxy(soap_mode imode, soap_mode omode)
{	NetIntProxy_init(imode, omode);
}

void NetIntProxy::NetIntProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns", "urn:hell", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	if (!this->namespaces)
		this->namespaces = namespaces;
}

NetIntProxy::~NetIntProxy()
{ }

void NetIntProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void NetIntProxy::soap_noheader()
{	header = NULL;
}

const SOAP_ENV__Fault *NetIntProxy::soap_fault()
{	return this->fault;
}

const char *NetIntProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *NetIntProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int NetIntProxy::soap_close_socket()
{	return soap_closesock(this);
}

void NetIntProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void NetIntProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *NetIntProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int NetIntProxy::setEndPoint(std::string endPoint, int &result)
{	struct soap *soap = this;
	struct ns__setEndPoint soap_tmp_ns__setEndPoint;
	struct ns__setEndPointResponse *soap_tmp_ns__setEndPointResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__setEndPoint.endPoint = endPoint;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__setEndPoint(soap, &soap_tmp_ns__setEndPoint);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__setEndPoint(soap, &soap_tmp_ns__setEndPoint, "ns:setEndPoint", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__setEndPoint(soap, &soap_tmp_ns__setEndPoint, "ns:setEndPoint", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_int(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__setEndPointResponse = soap_get_ns__setEndPointResponse(soap, NULL, "ns:setEndPointResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__setEndPointResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::exchangeSpecimens(std::string specimentList, std::string &result)
{	struct soap *soap = this;
	struct ns__exchangeSpecimens soap_tmp_ns__exchangeSpecimens;
	struct ns__exchangeSpecimensResponse *soap_tmp_ns__exchangeSpecimensResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__exchangeSpecimens.specimentList = specimentList;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__exchangeSpecimens(soap, &soap_tmp_ns__exchangeSpecimens);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__exchangeSpecimens(soap, &soap_tmp_ns__exchangeSpecimens, "ns:exchangeSpecimens", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__exchangeSpecimens(soap, &soap_tmp_ns__exchangeSpecimens, "ns:exchangeSpecimens", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_std__string(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__exchangeSpecimensResponse = soap_get_ns__exchangeSpecimensResponse(soap, NULL, "ns:exchangeSpecimensResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__exchangeSpecimensResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::getStatus(std::string &result)
{	struct soap *soap = this;
	struct ns__getStatus soap_tmp_ns__getStatus;
	struct ns__getStatusResponse *soap_tmp_ns__getStatusResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__getStatus(soap, &soap_tmp_ns__getStatus);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getStatus(soap, &soap_tmp_ns__getStatus, "ns:getStatus", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getStatus(soap, &soap_tmp_ns__getStatus, "ns:getStatus", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_std__string(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__getStatusResponse = soap_get_ns__getStatusResponse(soap, NULL, "ns:getStatusResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__getStatusResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::setParameter(std::string parameterChange, int &result)
{	struct soap *soap = this;
	struct ns__setParameter soap_tmp_ns__setParameter;
	struct ns__setParameterResponse *soap_tmp_ns__setParameterResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__setParameter.parameterChange = parameterChange;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__setParameter(soap, &soap_tmp_ns__setParameter);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__setParameter(soap, &soap_tmp_ns__setParameter, "ns:setParameter", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__setParameter(soap, &soap_tmp_ns__setParameter, "ns:setParameter", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_int(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__setParameterResponse = soap_get_ns__setParameterResponse(soap, NULL, "ns:setParameterResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__setParameterResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::runAlgorithm(bool &result)
{	struct soap *soap = this;
	struct ns__runAlgorithm soap_tmp_ns__runAlgorithm;
	struct ns__runAlgorithmResponse *soap_tmp_ns__runAlgorithmResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__runAlgorithm(soap, &soap_tmp_ns__runAlgorithm);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__runAlgorithm(soap, &soap_tmp_ns__runAlgorithm, "ns:runAlgorithm", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__runAlgorithm(soap, &soap_tmp_ns__runAlgorithm, "ns:runAlgorithm", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_bool(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__runAlgorithmResponse = soap_get_ns__runAlgorithmResponse(soap, NULL, "ns:runAlgorithmResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__runAlgorithmResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::setConections(std::string conections, int &result)
{	struct soap *soap = this;
	struct ns__setConections soap_tmp_ns__setConections;
	struct ns__setConectionsResponse *soap_tmp_ns__setConectionsResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__setConections.conections = conections;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__setConections(soap, &soap_tmp_ns__setConections);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__setConections(soap, &soap_tmp_ns__setConections, "ns:setConections", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__setConections(soap, &soap_tmp_ns__setConections, "ns:setConections", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_int(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__setConectionsResponse = soap_get_ns__setConectionsResponse(soap, NULL, "ns:setConectionsResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__setConectionsResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::sendConectionsProblem(std::string conectionProblem, int &result)
{	struct soap *soap = this;
	struct ns__sendConectionsProblem soap_tmp_ns__sendConectionsProblem;
	struct ns__sendConectionsProblemResponse *soap_tmp_ns__sendConectionsProblemResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__sendConectionsProblem.conectionProblem = conectionProblem;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__sendConectionsProblem(soap, &soap_tmp_ns__sendConectionsProblem);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__sendConectionsProblem(soap, &soap_tmp_ns__sendConectionsProblem, "ns:sendConectionsProblem", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__sendConectionsProblem(soap, &soap_tmp_ns__sendConectionsProblem, "ns:sendConectionsProblem", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_int(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__sendConectionsProblemResponse = soap_get_ns__sendConectionsProblemResponse(soap, NULL, "ns:sendConectionsProblemResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__sendConectionsProblemResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::registNode(std::string endPoint, int &result)
{	struct soap *soap = this;
	struct ns__registNode soap_tmp_ns__registNode;
	struct ns__registNodeResponse *soap_tmp_ns__registNodeResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__registNode.endPoint = endPoint;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__registNode(soap, &soap_tmp_ns__registNode);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__registNode(soap, &soap_tmp_ns__registNode, "ns:registNode", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__registNode(soap, &soap_tmp_ns__registNode, "ns:registNode", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_int(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__registNodeResponse = soap_get_ns__registNodeResponse(soap, NULL, "ns:registNodeResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__registNodeResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::unRegistNode(std::string endPoint, int &result)
{	struct soap *soap = this;
	struct ns__unRegistNode soap_tmp_ns__unRegistNode;
	struct ns__unRegistNodeResponse *soap_tmp_ns__unRegistNodeResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__unRegistNode.endPoint = endPoint;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__unRegistNode(soap, &soap_tmp_ns__unRegistNode);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__unRegistNode(soap, &soap_tmp_ns__unRegistNode, "ns:unRegistNode", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__unRegistNode(soap, &soap_tmp_ns__unRegistNode, "ns:unRegistNode", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_int(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__unRegistNodeResponse = soap_get_ns__unRegistNodeResponse(soap, NULL, "ns:unRegistNodeResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__unRegistNodeResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::getSpecimens(std::string &result)
{	struct soap *soap = this;
	struct ns__getSpecimens soap_tmp_ns__getSpecimens;
	struct ns__getSpecimensResponse *soap_tmp_ns__getSpecimensResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__getSpecimens(soap, &soap_tmp_ns__getSpecimens);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getSpecimens(soap, &soap_tmp_ns__getSpecimens, "ns:getSpecimens", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getSpecimens(soap, &soap_tmp_ns__getSpecimens, "ns:getSpecimens", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_std__string(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__getSpecimensResponse = soap_get_ns__getSpecimensResponse(soap, NULL, "ns:getSpecimensResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__getSpecimensResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::getAppStatus(std::string &result)
{	struct soap *soap = this;
	struct ns__getAppStatus soap_tmp_ns__getAppStatus;
	struct ns__getAppStatusResponse *soap_tmp_ns__getAppStatusResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__getAppStatus(soap, &soap_tmp_ns__getAppStatus);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getAppStatus(soap, &soap_tmp_ns__getAppStatus, "ns:getAppStatus", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getAppStatus(soap, &soap_tmp_ns__getAppStatus, "ns:getAppStatus", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_std__string(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__getAppStatusResponse = soap_get_ns__getAppStatusResponse(soap, NULL, "ns:getAppStatusResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__getAppStatusResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::setAppParameter(std::string parameterChange, int &result)
{	struct soap *soap = this;
	struct ns__setAppParameter soap_tmp_ns__setAppParameter;
	struct ns__setAppParameterResponse *soap_tmp_ns__setAppParameterResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__setAppParameter.parameterChange = parameterChange;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__setAppParameter(soap, &soap_tmp_ns__setAppParameter);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__setAppParameter(soap, &soap_tmp_ns__setAppParameter, "ns:setAppParameter", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__setAppParameter(soap, &soap_tmp_ns__setAppParameter, "ns:setAppParameter", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_int(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__setAppParameterResponse = soap_get_ns__setAppParameterResponse(soap, NULL, "ns:setAppParameterResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__setAppParameterResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::newTask(std::string task, std::string &result)
{	struct soap *soap = this;
	struct ns__newTask soap_tmp_ns__newTask;
	struct ns__newTaskResponse *soap_tmp_ns__newTaskResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__newTask.task = task;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__newTask(soap, &soap_tmp_ns__newTask);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__newTask(soap, &soap_tmp_ns__newTask, "ns:newTask", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__newTask(soap, &soap_tmp_ns__newTask, "ns:newTask", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_std__string(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__newTaskResponse = soap_get_ns__newTaskResponse(soap, NULL, "ns:newTaskResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__newTaskResponse->result;
	return soap_closesock(soap);
}

int NetIntProxy::getConnectedNodes(std::string &conections)
{	struct soap *soap = this;
	struct ns__getConnectedNodes soap_tmp_ns__getConnectedNodes;
	struct ns__getConnectedNodesResponse *soap_tmp_ns__getConnectedNodesResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__getConnectedNodes(soap, &soap_tmp_ns__getConnectedNodes);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__getConnectedNodes(soap, &soap_tmp_ns__getConnectedNodes, "ns:getConnectedNodes", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__getConnectedNodes(soap, &soap_tmp_ns__getConnectedNodes, "ns:getConnectedNodes", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&conections)
		return soap_closesock(soap);
	soap_default_std__string(soap, &conections);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__getConnectedNodesResponse = soap_get_ns__getConnectedNodesResponse(soap, NULL, "ns:getConnectedNodesResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	conections = soap_tmp_ns__getConnectedNodesResponse->conections;
	return soap_closesock(soap);
}

int NetIntProxy::sendMessage(std::string message, int &result)
{	struct soap *soap = this;
	struct ns__sendMessage soap_tmp_ns__sendMessage;
	struct ns__sendMessageResponse *soap_tmp_ns__sendMessageResponse;
	const char *soap_action = NULL;
	soap->encodingStyle = "";
	soap_tmp_ns__sendMessage.message = message;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__sendMessage(soap, &soap_tmp_ns__sendMessage);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__sendMessage(soap, &soap_tmp_ns__sendMessage, "ns:sendMessage", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__sendMessage(soap, &soap_tmp_ns__sendMessage, "ns:sendMessage", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&result)
		return soap_closesock(soap);
	soap_default_int(soap, &result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__sendMessageResponse = soap_get_ns__sendMessageResponse(soap, NULL, "ns:sendMessageResponse", "");
	if (soap->error)
	{	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
			return soap_recv_fault(soap);
		return soap_closesock(soap);
	}
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	result = soap_tmp_ns__sendMessageResponse->result;
	return soap_closesock(soap);
}
/* End of client proxy code */

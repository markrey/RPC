/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of RPCDDS is licensed to you under the terms described in the
 * RPCDDS_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file ServerExceptionServer.cxx
 * This source file contains the definition of the server for interface ServerException.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "ServerExceptionServer.h"
#include "transports/UDPTransport.h"
#include "transports/TCPTransport.h"
#include "exceptions/ServerInternalException.h"
#include "ServerExceptionRequestReplyPlugin.h"

#include "ServerExceptionServerRPCSupport.h"

ServerExceptionServer::ServerExceptionServer(std::string serviceName, eProsima::RPCDDS::ServerStrategy *strategy,
    int domainId) :
    Server(serviceName, strategy, NULL, domainId)
{
    _impl = new ServerExceptionServerImpl();

    createRPCs();
}

ServerExceptionServer::ServerExceptionServer(std::string serviceName, eProsima::RPCDDS::ServerStrategy *strategy,
    eProsima::RPCDDS::Transport *transport, int domainId) :
    Server(serviceName, strategy, transport, domainId)
{
    _impl = new ServerExceptionServerImpl();
    
    createRPCs();
}

ServerExceptionServer::~ServerExceptionServer()
{
    delete _impl;    
}

void ServerExceptionServer::createRPCs()
{
    this->setRPC(new ServerException_sendExceptionServerRPC("sendException", this,
                ServerException_sendExceptionRequestUtils::registerType(getParticipant()),
                ServerException_sendExceptionReplyUtils::registerType(getParticipant()),
                &ServerExceptionServer::sendException));
    this->setRPC(new ServerException_sendExceptionTwoServerRPC("sendExceptionTwo", this,
                ServerException_sendExceptionTwoRequestUtils::registerType(getParticipant()),
                ServerException_sendExceptionTwoReplyUtils::registerType(getParticipant()),
                &ServerExceptionServer::sendExceptionTwo));
    this->setRPC(new ServerException_sendExceptionThreeServerRPC("sendExceptionThree", this,
                ServerException_sendExceptionThreeRequestUtils::registerType(getParticipant()),
                ServerException_sendExceptionThreeReplyUtils::registerType(getParticipant()),
                &ServerExceptionServer::sendExceptionThree));

}

void ServerExceptionServer::sendException(eProsima::RPCDDS::Server *server, void *requestData, eProsima::RPCDDS::ServerRPC *service) 
{ 
    ServerExceptionServer *srv = dynamic_cast<ServerExceptionServer*>(server);
   
    ServerException_sendExceptionReply replyData;
    

    ServerException_sendExceptionRequestUtils::extractTypeData(*(ServerException_sendExceptionRequest*)requestData);

    try
    {
srv->_impl->sendException();

        ServerException_sendExceptionReplyUtils::setTypeData(replyData);
        replyData.header.rpcddsRetCode = eProsima::RPCDDS::OPERATION_SUCCESSFUL;
        replyData.header.rpcddsRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::RPCDDS::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.rpcddsRetCode = eProsima::RPCDDS::SERVER_INTERNAL_ERROR;
        replyData.header.rpcddsRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    ServerException_sendExceptionRequestTypeSupport::delete_data((ServerException_sendExceptionRequest*)requestData);
    
}
void ServerExceptionServer::sendExceptionTwo(eProsima::RPCDDS::Server *server, void *requestData, eProsima::RPCDDS::ServerRPC *service) 
{ 
    ServerExceptionServer *srv = dynamic_cast<ServerExceptionServer*>(server);
    char*  message = NULL;
    char*  message2 = NULL;
    char*  message3 = NULL;
    char*  sendExceptionTwo_ret = NULL;   
    ServerException_sendExceptionTwoReply replyData;
    

    ServerException_sendExceptionTwoRequestUtils::extractTypeData(*(ServerException_sendExceptionTwoRequest*)requestData, message, message2);

    try
    {
        sendExceptionTwo_ret = srv->_impl->sendExceptionTwo(message, message2, message3);

        ServerException_sendExceptionTwoReplyUtils::setTypeData(replyData, message2, message3, sendExceptionTwo_ret);
        replyData.header.rpcddsRetCode = eProsima::RPCDDS::OPERATION_SUCCESSFUL;
        replyData.header.rpcddsRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::RPCDDS::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.rpcddsRetCode = eProsima::RPCDDS::SERVER_INTERNAL_ERROR;
        replyData.header.rpcddsRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    ServerException_sendExceptionTwoRequestTypeSupport::delete_data((ServerException_sendExceptionTwoRequest*)requestData);
    
    if(sendExceptionTwo_ret != NULL) free(sendExceptionTwo_ret);
    if(message2 != NULL) free(message2);
    if(message3 != NULL) free(message3);
}
void ServerExceptionServer::sendExceptionThree(eProsima::RPCDDS::Server *server, void *requestData, eProsima::RPCDDS::ServerRPC *service) 
{ 
    ServerExceptionServer *srv = dynamic_cast<ServerExceptionServer*>(server);
    Estructura es;
    Estructura es2;
    Estructura es3;
    memset(&es3, 0, sizeof(Estructura));
    Estructura sendExceptionThree_ret;
    memset(&sendExceptionThree_ret, 0, sizeof(Estructura));   
    ServerException_sendExceptionThreeReply replyData;
    
    Estructura_initialize(&es2);

    ServerException_sendExceptionThreeRequestUtils::extractTypeData(*(ServerException_sendExceptionThreeRequest*)requestData, es, es2);

    try
    {
        sendExceptionThree_ret = srv->_impl->sendExceptionThree(es, es2, es3);

        ServerException_sendExceptionThreeReplyUtils::setTypeData(replyData, es2, es3, sendExceptionThree_ret);
        replyData.header.rpcddsRetCode = eProsima::RPCDDS::OPERATION_SUCCESSFUL;
        replyData.header.rpcddsRetMsg = NULL;

        service->sendReply(requestData, &replyData);
    }
    catch(const eProsima::RPCDDS::ServerInternalException &ex)
    {
        memset(&replyData, 0, sizeof(replyData));
        replyData.header.rpcddsRetCode = eProsima::RPCDDS::SERVER_INTERNAL_ERROR;
        replyData.header.rpcddsRetMsg = (char*)ex.what();
        
        service->sendReply(requestData, &replyData);
    }
    
    ServerException_sendExceptionThreeRequestTypeSupport::delete_data((ServerException_sendExceptionThreeRequest*)requestData);
    
    Estructura_finalize(&sendExceptionThree_ret);
    Estructura_finalize(&es2);
    Estructura_finalize(&es3);
}
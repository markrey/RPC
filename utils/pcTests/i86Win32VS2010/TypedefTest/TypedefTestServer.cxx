/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "TypedefTestServer.h"
#include "TypedefTestRequestReplyPlugin.h"
#include "TypedefTestServerRemoteServiceSupport.h"

TypedefTestServer::TypedefTestServer(int domainId, unsigned int threadCount,
const char *qosLibrary, const char *qosProfile) : DDSCSServer(domainId, threadCount, qosLibrary, qosProfile)
{
    _impl = new TypedefTestImpl();
    
    this->setRemoteService(new getLargoServerRemoteService("getLargo", this,
                getLargoRequestUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                getLargoReplyUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                &TypedefTestServer::getLargo, getParticipant()));
    this->setRemoteService(new getLarguisimoServerRemoteService("getLarguisimo", this,
                getLarguisimoRequestUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                getLarguisimoReplyUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                &TypedefTestServer::getLarguisimo, getParticipant()));
    this->setRemoteService(new getDatosDefServerRemoteService("getDatosDef", this,
                getDatosDefRequestUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                getDatosDefReplyUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                &TypedefTestServer::getDatosDef, getParticipant()));
    this->setRemoteService(new getDatosDefondoServerRemoteService("getDatosDefondo", this,
                getDatosDefondoRequestUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                getDatosDefondoReplyUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                &TypedefTestServer::getDatosDefondo, getParticipant()));
    this->setRemoteService(new getCadenaServerRemoteService("getCadena", this,
                getCadenaRequestUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                getCadenaReplyUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                &TypedefTestServer::getCadena, getParticipant()));
    this->setRemoteService(new getCorreaServerRemoteService("getCorrea", this,
                getCorreaRequestUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                getCorreaReplyUtils::registerType(getParticipant()),
    "TypedefTest_Library",
    "TypedefTest_Profile",
                &TypedefTestServer::getCorrea, getParticipant()));

}
TypedefTestServer::~TypedefTestServer()
{
    delete _impl;    
}

void TypedefTestServer::getLargo(DDSCSServer *server, void *requestData, ServerRemoteService *service) 
{ 
    TypedefTestServer *srv = (TypedefTestServer*)server;
    largo  l1 ;       
   
    largo  l2 ;    
    largo  getLargo_ret ;       
    DDSCSMessages  returnedValue ;        
    getLargoReply *replyData = NULL;

    getLargoRequestUtils::extractTypeData((getLargoRequest*)requestData, l1    );
                                         
    returnedValue = srv->_impl->getLargo(l1    ,l2    , getLargo_ret    );
           
    replyData = getLargoReplyUtils::createTypeData(l2    , getLargo_ret    );
                                                  
    // sendReply takes care of deleting the data
    service->sendReply(requestData, replyData, returnedValue);
    
        
        
        
}
void TypedefTestServer::getLarguisimo(DDSCSServer *server, void *requestData, ServerRemoteService *service) 
{ 
    TypedefTestServer *srv = (TypedefTestServer*)server;
    larguisimo  ll1 ;       
   
    larguisimo  ll2 ;    
    larguisimo  getLarguisimo_ret ;       
    DDSCSMessages  returnedValue ;        
    getLarguisimoReply *replyData = NULL;

    getLarguisimoRequestUtils::extractTypeData((getLarguisimoRequest*)requestData, ll1    );
                                         
    returnedValue = srv->_impl->getLarguisimo(ll1    ,ll2    , getLarguisimo_ret    );
           
    replyData = getLarguisimoReplyUtils::createTypeData(ll2    , getLarguisimo_ret    );
                                                  
    // sendReply takes care of deleting the data
    service->sendReply(requestData, replyData, returnedValue);
    
        
        
        
}
void TypedefTestServer::getDatosDef(DDSCSServer *server, void *requestData, ServerRemoteService *service) 
{ 
    TypedefTestServer *srv = (TypedefTestServer*)server;
    DatosDef *d1 = DatosDefPluginSupport_create_data();       
   
    DatosDef *d2 = DatosDefPluginSupport_create_data();    
    DatosDef *getDatosDef_ret = DatosDefPluginSupport_create_data();       
    DDSCSMessages  returnedValue ;        
    getDatosDefReply *replyData = NULL;

    getDatosDefRequestUtils::extractTypeData((getDatosDefRequest*)requestData, *d1    );
                                         
    returnedValue = srv->_impl->getDatosDef(*d1    ,*d2    , *getDatosDef_ret    );
           
    replyData = getDatosDefReplyUtils::createTypeData(*d2    , *getDatosDef_ret    );
                                                  
    // sendReply takes care of deleting the data
    service->sendReply(requestData, replyData, returnedValue);
    
    DatosDefPluginSupport_destroy_data(d1);    
    DatosDefPluginSupport_destroy_data(d2);    
    DatosDefPluginSupport_destroy_data(getDatosDef_ret);    
}
void TypedefTestServer::getDatosDefondo(DDSCSServer *server, void *requestData, ServerRemoteService *service) 
{ 
    TypedefTestServer *srv = (TypedefTestServer*)server;
    DatosDefondo *dd1 = DatosDefondoPluginSupport_create_data();       
   
    DatosDefondo *dd2 = DatosDefondoPluginSupport_create_data();    
    DatosDefondo *getDatosDefondo_ret = DatosDefondoPluginSupport_create_data();       
    DDSCSMessages  returnedValue ;        
    getDatosDefondoReply *replyData = NULL;

    getDatosDefondoRequestUtils::extractTypeData((getDatosDefondoRequest*)requestData, *dd1    );
                                         
    returnedValue = srv->_impl->getDatosDefondo(*dd1    ,*dd2    , *getDatosDefondo_ret    );
           
    replyData = getDatosDefondoReplyUtils::createTypeData(*dd2    , *getDatosDefondo_ret    );
                                                  
    // sendReply takes care of deleting the data
    service->sendReply(requestData, replyData, returnedValue);
    
    DatosDefondoPluginSupport_destroy_data(dd1);    
    DatosDefondoPluginSupport_destroy_data(dd2);    
    DatosDefondoPluginSupport_destroy_data(getDatosDefondo_ret);    
}
void TypedefTestServer::getCadena(DDSCSServer *server, void *requestData, ServerRemoteService *service) 
{ 
    TypedefTestServer *srv = (TypedefTestServer*)server;
    cadena  c1  = NULL;       
   
    cadena  c2  = NULL;    
    cadena  getCadena_ret  = NULL;       
    DDSCSMessages  returnedValue ;        
    getCadenaReply *replyData = NULL;

    getCadenaRequestUtils::extractTypeData((getCadenaRequest*)requestData, c1    );
                                         
    returnedValue = srv->_impl->getCadena(c1    ,c2    , getCadena_ret    );
           
    replyData = getCadenaReplyUtils::createTypeData(c2    , getCadena_ret    );
                                                  
    // sendReply takes care of deleting the data
    service->sendReply(requestData, replyData, returnedValue);
    
    if(c1 != NULL) DDS_String_free(c1);    
    if(c2 != NULL) DDS_String_free(c2);    
    if(getCadena_ret != NULL) DDS_String_free(getCadena_ret);    
}
void TypedefTestServer::getCorrea(DDSCSServer *server, void *requestData, ServerRemoteService *service) 
{ 
    TypedefTestServer *srv = (TypedefTestServer*)server;
    correa  cc1  = NULL;       
   
    correa  cc2  = NULL;    
    correa  getCorrea_ret  = NULL;       
    DDSCSMessages  returnedValue ;        
    getCorreaReply *replyData = NULL;

    getCorreaRequestUtils::extractTypeData((getCorreaRequest*)requestData, cc1    );
                                         
    returnedValue = srv->_impl->getCorrea(cc1    ,cc2    , getCorrea_ret    );
           
    replyData = getCorreaReplyUtils::createTypeData(cc2    , getCorrea_ret    );
                                                  
    // sendReply takes care of deleting the data
    service->sendReply(requestData, replyData, returnedValue);
    
    if(cc1 != NULL) DDS_String_free(cc1);    
    if(cc2 != NULL) DDS_String_free(cc2);    
    if(getCorrea_ret != NULL) DDS_String_free(getCorrea_ret);    
}
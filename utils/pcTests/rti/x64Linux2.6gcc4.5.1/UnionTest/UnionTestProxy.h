#ifndef _UnionTest_PROXY_H_
#define _UnionTest_PROXY_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "client/Client.h"
#include "UnionTestRequestReplyUtils.h"
#include "UnionTestClientRPCSupport.h"

class UnionTest_getEmpleado
{
    public:
        virtual void getEmpleado(/*inout*/ const Empleado& em2, /*out*/ const Empleado& em3, /*out*/ const Empleado& getEmpleado_ret)
        {
        }
   
        virtual void error(eProsima::DDSRPC::ReturnMessage message)
        {
        }
};

/**
 * \brief This class implements a specific server's proxy for the defined interface by user.
 */
class UnionTestProxy : public eProsima::DDSRPC::Client
{
    public:
    
        /**
         * \brief Default constructor. The server's proxy will use the default eProsima::DDSRPC::UDPTransport.
         *
         * \param domainId The DDS domain that DDS will use to work. Default value: 0
         * \param timeout Timeout used in each call to remotely procedures.
         *        If the call exceeds the time, a eProsima::DDSRPC::ServerTimeoutException is thrown.
         */
        UnionTestProxy(int domainId = 0, long timeout = 10000);

        /**
         * \brief This constructor sets the transport that will be used by the server's proxy.
         *
         * \param transport The network transport that server's proxy has to use.
         *        This transport's object is not deleted by this class in its destrcutor. Cannot be NULL.
         * \param domainId The DDS domain that DDS will use to work. Default value: 0
         * \param timeout Timeout used in each call to remotely procedures.
         *        If the call exceeds the time, a eProsima::DDSRPC::ServerTimeoutException is thrown.
         */
        UnionTestProxy(eProsima::DDSRPC::Transport *transport, int domainId = 0, long timeout = 10000);

        /// \brief The default destructor.
        virtual ~UnionTestProxy();
        
         
        Empleado getEmpleado(/*in*/ const Empleado& em1, /*inout*/ Empleado& em2, /*out*/ Empleado& em3);
        
         
        void getEmpleado_async(UnionTest_getEmpleado &obj, /*in*/ const Empleado& em1, /*inout*/ const Empleado& em2);
        
    private:
        /**
         * \brief This function creates all RPC endpoints for each remote procedure.
         */
        void createRPCs();
        
        eProsima::DDSRPC::ClientRPC *getEmpleado_Service; 
};

#endif // _UnionTest_PROXY_H_
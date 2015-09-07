/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * fastrpc_LICENSE file included in this fastrpc distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorProxy.h
 * This header file contains the declaration of the proxy for all interfaces.
 *
 * This file was generated by the tool fastrpcgen.
 */

#ifndef _Calculator_PROXY_H_
#define _Calculator_PROXY_H_

#include "fastrpc/client/Proxy.h"
#include "Calculator.h"
namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
            class CalculatorProtocol;
        }
    }
}

/*!
 * @brief This class implements a specific server's proxy for the defined interface Calculator.
 * @ingroup CALCULATOR
 */
class RPCUSERDllExport CalculatorProxy : public eprosima::rpc::proxy::Proxy
{
    public:
   
        /*!
         * @brief This constructor sets the transport that will be used by the server's proxy.
         *
         * @param transport The network transport that server's proxy has to use.
         *        This transport's object is not deleted by this class in its destructor. Cannot be NULL.
         * @param protocol The protocol used to send the information over the transport.
         *        This protocol's object is not deleted by this class in its destructor. Cannot be NULL.
         * @exception eprosima::rpc::exception::InitializeException This exception is thrown when the initialization was wrong.
         */
        CalculatorProxy(eprosima::rpc::transport::ProxyTransport &transport,
            eprosima::rpc::protocol::CalculatorProtocol &protocol);

        //! @brief Destructor.
        virtual ~CalculatorProxy();
        
        //! @brief Proxy method for the operation addition.
        int32_t addition(/*in*/ int32_t value1, /*in*/ int32_t value2);


        //! @brief Proxy method for the operation subtraction.
        int32_t subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2);


};


#endif // _Calculator_PROXY_H_
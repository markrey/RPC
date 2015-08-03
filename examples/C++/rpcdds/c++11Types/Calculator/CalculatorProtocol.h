/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorProtocol.h
 * This header file contains the declaration of the interface for all protocols.
 *
 * This file was generated by the tool rpcddsgen.
 */

#ifndef _Calculator_PROTOCOL_H_
#define _Calculator_PROTOCOL_H_

#include <rpcdds/protocols/Protocol.h>
#include "Calculator.h"
#include "CalculatorAsyncCallbackHandlers.h"
#include "CalculatorServerImpl.h"

namespace eprosima
{
    namespace rpc
    {
        namespace protocol
        {
            /*!
             * @brief Protocol base class for the specific application
             * @ingroup CALCULATOR
             */
            class RPCUSERDllExport CalculatorProtocol : public Protocol
            {
                public:
                
                   /*!
                    * @brief This method sets the transport for the communications. It has to be implemented by the children classes.
                    * @param transport Transport to use.
                    * @return True if the assignment is successful, false otherwise
                    */
                    virtual bool setTransport(eprosima::rpc::transport::Transport &transport) = 0;
                    
                        /*!
                         * @brief In some protocols this function activates needed entities to use an interface.
                         * @param interfaceName Interface name.
                         * @return Whether the activation works successfully.
                         */
                    virtual bool activateInterface(const char* interfaceName) = 0;
                    
                                       /*!
                                        * @brief This method links a specific servant with the protocol.
                                        * @param impl Servant implementation.
                                        */
                                        void linkCalculatorImpl(CalculatorServerImpl &impl)
                                        {
                                            _Calculator_impl = &impl;
                                        }
                                        
                             
                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation addition.
                     *        It has to be implemented by the child classes.
                     */
                    virtual int32_t Calculator_addition(/*in*/ int32_t value1, /*in*/ int32_t value2) = 0;
                    /*!
                     * @brief This asynchronous method implements the proxy part of the protocol for the operation addition.
                     *        It has to be implemented by the child classes.
                     */
                    virtual void Calculator_addition_async(Calculator_additionCallbackHandler &obj, /*in*/ int32_t value1, /*in*/ int32_t value2) = 0;

                    /*!
                     * @brief This method implements the proxy part of the protocol for the operation subtraction.
                     *        It has to be implemented by the child classes.
                     */
                    virtual int32_t Calculator_subtraction(/*in*/ int32_t value1, /*in*/ int32_t value2) = 0;
                    /*!
                     * @brief This asynchronous method implements the proxy part of the protocol for the operation subtraction.
                     *        It has to be implemented by the child classes.
                     */
                    virtual void Calculator_subtraction_async(Calculator_subtractionCallbackHandler &obj, /*in*/ int32_t value1, /*in*/ int32_t value2) = 0;





                    
                protected:
                
                    CalculatorProtocol() : Protocol()
                                         
                                        , _Calculator_impl(NULL)
                                        
                    {}
                    
                    virtual ~CalculatorProtocol(){}
                
                	                     
                	                    CalculatorServerImpl *_Calculator_impl;
                	                    
                    
            };
        } // namespace protocol
    } // namespace rpc
} // namespace eprosima

#endif // _Calculator_PROTOCOL_H_

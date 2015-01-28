/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * rpcdds_LICENSE file included in this rpcdds distribution.
 *
 *************************************************************************
 * 
 * @file CalculatorServer.cxx
 * This source file contains the definition of the server for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "CalculatorServer.h"
#include <rpcdds/strategies/ServerStrategy.h>
#include <rpcdds/transports/ServerTransport.h>
#include "CalculatorProtocol.h"
#include <rpcdds/exceptions/ServerInternalException.h>

CalculatorServer::CalculatorServer(eprosima::rpc::strategy::ServerStrategy &strategy, eprosima::rpc::transport::ServerTransport &transport,
            eprosima::rpc::protocol::CalculatorProtocol &protocol, CalculatorServerImpl &servant) :
    Server(strategy, transport, protocol), _impl(servant)
{
   protocol.activateInterface("Calculator");
   protocol.linkCalculatorImpl(servant);
}

CalculatorServer::~CalculatorServer()
{
    //TODO Unlink an deactivate.
}




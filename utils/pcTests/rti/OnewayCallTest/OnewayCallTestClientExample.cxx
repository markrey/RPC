/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file OnewayCallTestClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "OnewayCallTestProxy.h"
#include "OnewayCallTest.h"
#include "OnewayCallTestDDSProtocol.h"
#include "fastrpc/transports/dds/UDPProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"
#include <fastrpc/utils/macros/strdup.h>

#include <iostream>

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    OnewayCallTestProtocol *protocol = NULL;
    UDPProxyTransport *transport = NULL;
    OnewayCallTestProxy *proxy = NULL;
    
    // Creation of the proxy for interface "OnewayCallTest".
    try
    {
        protocol = new OnewayCallTestProtocol();
        transport = new UDPProxyTransport("OnewayCallTestService", "Instance");
        proxy = new OnewayCallTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    DDS_Long lo1 = 10;       

    try
    {
        proxy->setLong(lo1);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<setLong>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Long long_ret = 0;

    try
    {
        long_ret = proxy->getLong();

        if(long_ret != 10)
        {
            std::cout << "TEST FAILED<getLong>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getLong>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Boolean bo1 = RTI_TRUE;       

    try
    {
        proxy->setBoolean(bo1);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<setBoolean>: " << ex.what() << std::endl;
        _exit(-1);
    }

    DDS_Boolean bo_ret = 0;

    try
    {
        bo_ret = proxy->getBoolean();

        if(bo_ret != RTI_TRUE)
        {
            std::cout << "TEST FAILED<getBoolean>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getBoolean>: " << ex.what() << std::endl;
        _exit(-1);
    }

    char *s1 = STRDUP("Ricardo");       

    try
    {
        proxy->setString(s1);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<setString>: " << ex.what() << std::endl;
        _exit(-1);
    }

    if(s1 != NULL) free(s1);

    char* s_ret = NULL;

    try
    {
        s_ret = proxy->getString();

        if(strcmp(s_ret, "Ricardo") != 0)
        {
            std::cout << "TEST FAILED<getString>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getString>: " << ex.what() << std::endl;
        _exit(-1);
    }

    if(s_ret != NULL) free(s_ret);

    Structure st1;
    Structure_initialize(&st1);
    st1.dato = 10;
    st1.message = STRDUP("Jaime");

    try
    {
        proxy->setStruct(st1);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<setStruct>: " << ex.what() << std::endl;
        _exit(-1);
    }

    Structure_finalize(&st1);

    Structure st_ret;
    Structure_initialize(&st_ret);

    try
    {
        st_ret = proxy->getStruct();

        if(st_ret.dato != 10 ||
                strcmp(st_ret.message, "Jaime") != 0)
        {
            std::cout << "TEST FAILED<getStruct>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getStruct>: " << ex.what() << std::endl;
        _exit(-1);
    }

	Structure_finalize(&st_ret);

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete proxy;
    delete transport;
    delete protocol;

    _exit(0);
    return 0;
}

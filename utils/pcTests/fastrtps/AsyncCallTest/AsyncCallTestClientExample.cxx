/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file Client.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "AsyncCallTestProxy.h"
#include "AsyncCallTest.h"
#include "AsyncCallTestDDSProtocol.h"
#include <fastrpc/transports/dds/RTPSProxyTransport.h>
#include <fastrpc/exceptions/Exceptions.h>
#include <fastrpc/utils/Utilities.h>

#include <iostream>
#ifdef __linux
#include <unistd.h>
#endif

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

class GetLongHandler : public AsyncCallTest_getLongCallbackHandler
{
    public:

        GetLongHandler() : m_state(0){}

        void getLong(/*inout*/ int32_t lo2, /*out*/ int32_t lo3, /*out*/ int32_t getLong_ret)
        {
            if(lo3 != 2 ||
                    getLong_ret != 1 ||
                    lo2 != 3)
            {
                std::cout << "TEST FAILED<getLong>: Wrong values" << std::endl;
                m_state = 2;
                return;
            }

            m_state = 1;
        }

        void on_exception(const SystemException &ex)
        {
            std::cout << "TEST FAILED<on_exception>: " << ex.what() << std::endl;
            m_state = 2;
        }

        int getState() const
        {
            return m_state;
        }

    private:

        int m_state;
};

class GetBooleanHandler : public AsyncCallTest_getBooleanCallbackHandler
{
    public:
        GetBooleanHandler() : m_state(0){}

        void getBoolean(/*inout*/ bool bo2, /*out*/ bool bo3, /*out*/ bool getBoolean_ret)
        {
            if(bo3 != false ||
                    getBoolean_ret != true ||
                    bo2 != true)
            {
                std::cout << "TEST FAILED<getBoolean>: Wrong values" << std::endl;
                m_state = 2;
                return;
            }

            m_state = 1;
        }

        void on_exception(const SystemException &ex)
        {
            std::cout << "TEST FAILED<on_exception>: " << ex.what() << std::endl;
            m_state = 2;
        }

        int getState() const
        {
            return m_state;
        }

    private:

        int m_state;
};

class GetStringHandler : public AsyncCallTest_getStringCallbackHandler
{
    public:

        GetStringHandler() : m_state(0){}

        void getString(/*inout*/ const std::string& s2, /*out*/ const std::string& s3, /*out*/ const std::string& getString_ret)
        {
            if(s3.compare("PRUEBA2") != 0 ||
                    getString_ret.compare("PRUEBA") != 0 ||
                    s2.compare("PRUEBAPRUEBA2") != 0)
            {
                std::cout << "TEST FAILED<getString>: Wrong values" << std::endl;
                m_state = 2;
                return;
            }       

            m_state = 1;
        }
   
        void on_exception(const SystemException &ex)
        {
            std::cout << "TEST FAILED<on_exception>: " << ex.what() << std::endl;
            m_state = 2;
        }

        int getState() const
        {
            return m_state;
        }

    private:

        int m_state;
};

class DuplicateHandler : public AsyncCallTest_duplicateCallbackHandler
{
    public:
        DuplicateHandler() : m_state(0){}

        void duplicate(/*out*/ const Structure& duplicate_ret)
        {
            if(duplicate_ret.dato() != 10 ||
                    duplicate_ret.message().compare("HOLA") != 0)
            {
                std::cout << "TEST FAILED<duplicate>: Wrong values" << std::endl;
                m_state = 2;
                return;
            }

            m_state = 1;
        }
   
        void on_exception(const SystemException &ex)
        {
            std::cout << "TEST FAILED<on_exception>: " << ex.what() << std::endl;
            m_state = 2;
        }

        int getState() const
        {
            return m_state;
        }

    private:

        int m_state;
};

int main(int argc, char **argv)
{
    AsyncCallTestProtocol *protocol = NULL;
    RTPSProxyTransport *transport = NULL;
    AsyncCallTestProxy *proxy = NULL;

    try
    {
        protocol = new AsyncCallTestProtocol();
        transport = new RTPSProxyTransport("AsyncCallTestService", "Instance");
        proxy = new AsyncCallTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

    int32_t  lo1 = 1;       
    int32_t  lo2 = 2;       
    GetLongHandler getLong_handler;

    try
    {
        proxy->getLong_async(getLong_handler, lo1, lo2);

        while(getLong_handler.getState() == 0)
        {
            eprosima::rpc::sleep(1000);
        }

        if(getLong_handler.getState() == 2)
            _exit(-1);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getLong_async>: " << ex.what() << std::endl;
        _exit(-1);
    }

    bool  bo1 = true;       
    bool  bo2 = false;       
    GetBooleanHandler getBoolean_handler;

    try
    {
        proxy->getBoolean_async(getBoolean_handler, bo1, bo2);

        while(getBoolean_handler.getState() == 0)
        {
            eprosima::rpc::sleep(1000);
        }

        if(getBoolean_handler.getState() == 2)
            _exit(-1);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getBoolean_async>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::string s1  = "PRUEBA";       
    std::string s2  = "PRUEBA2";       
    GetStringHandler getString_handler;

    try
    {
        proxy->getString_async(getString_handler, s1, s2);

        while(getString_handler.getState() == 0)
        {
            eprosima::rpc::sleep(1000);
        }

        if(getString_handler.getState() == 2)
            _exit(-1);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getString_async>: " << ex.what() << std::endl;
        _exit(-1);
    }

    Structure ev;
    DuplicateHandler duplicate_handler;

    ev.dato(10);
    ev.message("HOLA");

    try
    {
        proxy->duplicate_async(duplicate_handler, ev);

        while(duplicate_handler.getState() == 0)
        {
            eprosima::rpc::sleep(1000);
        }

        if(duplicate_handler.getState() == 2)
            _exit(-1);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<duplicate_async>: " << ex.what() << std::endl;
        _exit(-1);
    }

	// Test the close of the proxy with pending asynchrnous tasks.
	int32_t  clo1 = 1;       
    int32_t  clo2 = 2;       
    GetLongHandler cgetLong_handler;
	bool  cbo1 = true;       
    bool  cbo2 = false;       
    GetBooleanHandler cgetBoolean_handler;
    std::string cs1  = "PRUEBA";       
    std::string cs2  = "PRUEBA2";       
    GetStringHandler cgetString_handler;  
    Structure cev;
    DuplicateHandler cduplicate_handler;

    cev.dato(10);
    cev.message("HOLA");

    try
    {
        proxy->getLong_async(cgetLong_handler, clo1, clo2);
		proxy->getBoolean_async(cgetBoolean_handler, cbo1, cbo2);
		proxy->getString_async(cgetString_handler, cs1, cs2);
		proxy->duplicate_async(cduplicate_handler, cev);
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<closing>: " << ex.what() << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESFULLY" << std::endl;

    delete(proxy);

    _exit(0);
    return 0;
}

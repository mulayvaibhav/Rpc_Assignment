#ifndef SERVER_RPC_H
#define SERVER_RPC_H

#include <string>
#include <ServerTransportInterface.h>


class ServerRpcInterface {
    public:
        ServerRpcInterface(ServerTransportInterface *ServerTransport_p);
        virtual ~ServerRpcInterface() {
        }
        virtual std::string handleRequest(const std::string& response)=0;
        virtual std::string sendResponse(const std::string& response)=0;   
    
    private:
        ServerTransportInterface * m_ServerTransport_p = nullptr;
};



#endif
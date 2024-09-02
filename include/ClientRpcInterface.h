#ifndef CLIENT_RPC_H
#define CLIENT_RPC_H

#include <string>
#include <ClientTransportInterface.h>


class ClientRpcInterface {
    public:
        ClientRpcInterface(ClientTransportInterface *ClientTransport_p);
        virtual ~ClientRpcInterface() {
        }
        virtual bool connect(const std::string, const int) = 0;
        virtual bool disconnect(void) = 0;       
        virtual bool callRemoteFunction(const std::string &funcName, int arg1= 0, int arg2 = 0)=0;
    
    private:
        ClientTransportInterface * m_ClientTransport_p = nullptr;
};



#endif
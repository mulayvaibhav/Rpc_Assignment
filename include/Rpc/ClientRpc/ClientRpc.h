#ifndef CLIENT_RPC_H
#define CLIENT_RPC_H

#include <string>
#include <ClientTransport.h>
#include <vector>
#include <any>

class ClientRpc {
    public:
        ClientRpc(ClientTransport *ClientTransport_p);
        virtual ~ClientRpc() {
        }
        virtual bool connect(const std::string, const int) = 0;
        virtual bool disconnect(void) = 0;       
        virtual std::string callRemoteFunction(const std::string &funcName, int arg1= 0, int arg2 = 0)=0;
    
    private:
        ClientTransport * m_ClientTransport_p = nullptr;
};



#endif
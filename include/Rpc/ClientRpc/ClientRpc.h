#ifndef CLIENT_RPC_H
#define CLIENT_RPC_H

#include <string>
#include <ClientTransport.h>
#include <vector>
#include <any>

class ClientRpc {
    public:
        ClientRpc(const ClientTransport *ClientTransport_p);
        virtual ~ClientRpc() {
        }
        virtual bool connect(const std::string, const int) = 0;
        virtual bool disconnect(void) = 0;       
    
    private:
        const ClientTransport * m_ClientTransport_p = nullptr;
};



#endif
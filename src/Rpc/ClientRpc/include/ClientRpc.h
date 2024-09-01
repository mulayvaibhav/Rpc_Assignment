#ifndef CLIENT_RPC_H
#define CLIENT_RPC_H

#include <string>
#include <ClientTransport.h>

namespace Rpc {

    class ClientRpc {

        public:
            ClientRpc(const ClientTransport *ClientTransport_p);
            virtual ~ClientRpc();
            virtual bool connect(const std::string, const int) = 0;
            virtual bool disconnect(void) = 0;
            virtual std::string callRemoteFunction(const std::string &funcName, Typename... args) = 0;
        
        private:
            ClientTransport * m_ClientTransport_p = nullptr;
    };

}

#endif
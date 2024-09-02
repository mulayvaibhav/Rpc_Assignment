#ifndef CLIENT_DREAM_RPC_H
#define CLIENT_DREAM_RPC_H

#include <ClientRpc.h>
#include <sstream>
#include <tuple>
#include <functional>

using namespace std;

class ClientDreamRpc : public ClientRpc {
    protected:
        ClientDreamRpc(ClientTransport *ClientTransport_p);
        static ClientDreamRpc* m_ClientDreamRpc_p;
    public:
        ~ClientDreamRpc() {
        }
        
        /**
         * Singletons should not be cloneable.
         */
        ClientDreamRpc(ClientDreamRpc &other) = delete;
        /**
         * Singletons should not be assignable.
         */
        void operator=(const ClientDreamRpc &) = delete;
        bool connect(const std::string, const int);
        bool disconnect(void);

        std::string callRemoteFunction(const std::string &funcName, int arg1= 0, int arg2 = 0);
        
        static ClientDreamRpc *GetInstance(ClientTransport *);
    private:
        ClientTransport * m_ClientTransport_p = nullptr;
        std::string m_server_name;
        uint32_t m_port_number;
        bool m_is_connected;
        
};
#endif
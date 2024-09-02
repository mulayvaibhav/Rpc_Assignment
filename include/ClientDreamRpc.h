#ifndef CLIENT_DREAM_RPC_H
#define CLIENT_DREAM_RPC_H

#include <ClientRpcInterface.h>

using namespace std;

class ClientDreamRpc : public ClientRpcInterface {
    protected:
        ClientDreamRpc(ClientTransportInterface *ClientTransport_p);
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
        bool callRemoteFunction(const std::string &funcName, int arg1= 0, int arg2 = 0);
        std::string handleResponse(const std::string&);
        static ClientDreamRpc *GetInstance(ClientTransportInterface *);
    private:
        ClientTransportInterface * m_ClientTransport_p = nullptr;
        std::string m_server_name;
        uint32_t m_port_number;
        bool m_is_connected;
        
};
#endif
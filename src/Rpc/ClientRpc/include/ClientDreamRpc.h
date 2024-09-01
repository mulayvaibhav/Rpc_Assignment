#ifndef CLIENT_RPC_H
#define CLIENT_RPC_H

#include <ClientRpc.h>

using namespace std;
namespace Rpc {

    class ClientDreamRpc : public ClientRpc{

        protected:
            ClientDreamRpc(const ClientTransport *ClientTransport_p): m_ClientTransport_p(ClientTransport_p) {
            
            }

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
            
            ~ClientDreamRpc();

            bool connect(const std::string, const int);
            bool disconnect(void) override;
            std::string callRemoteFunction(const std::string &funcName, Typename... args) override;

            static ClientDreamRpc *GetInstance(const std::string& value);
        private:
            ClientTransport * m_ClientTransport_p = nullptr;
            std::string m_server_name;
            uint32_t m_port_number;
            bool m_is_connected;
            
    };
}

#endif
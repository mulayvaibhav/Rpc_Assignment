#ifndef SERVER_DREAM_RPC_H
#define SERVER_DREAM_RPC_H

#include <ServerRpcInterface.h>

using namespace std;

class ServerDreamRpc : public ServerRpcInterface {
    protected:
        ServerDreamRpc(ServerTransportInterface *ServerTransport_p);
        static ServerDreamRpc* m_ServerDreamRpc_p;
    public:
        ~ServerDreamRpc() {
        }
        
        /**
         * Singletons should not be cloneable.
         */
        ServerDreamRpc(ServerDreamRpc &other) = delete;
        /**
         * Singletons should not be assignable.
         */
        void operator=(const ServerDreamRpc &) = delete;
        std::string handleRequest(const std::string& request) { return request; }
        std::string sendResponse(const std::string& response) {return response; }
        static ServerDreamRpc *GetInstance(ServerTransportInterface *);
    private:
        ServerTransportInterface * m_ServerTransport_p = nullptr;
        std::string m_server_name;
        uint32_t m_port_number;
        bool m_is_connected;
        
};
#endif
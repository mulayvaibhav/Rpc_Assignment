#ifndef CLIENT_DREAM_RPC_H
#define CLIENT_DREAM_RPC_H

#include <ClientRpc.h>
#include <sstream>
#include <tuple>

using namespace std;

class ClientDreamRpc : public ClientRpc {
    protected:
        ClientDreamRpc(const ClientTransport *ClientTransport_p);
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

        template<typename... Args>
        std::string callRemoteFunction(const std::string &funcName, Args... args);

        std::string callRemoteFunction(const std::string &funcName);
        
        static ClientDreamRpc *GetInstance(const ClientTransport *);
    private:
        template <typename... Args>
        std::string serializeArgs(Args... args) {
            std::ostringstream oss;
            std::vector<std::string> serializedArgs = {serialize(args)...};
            for (const auto& arg : serializedArgs) {
                oss << arg << " "; // Separate arguments with space
            }
            return oss.str();
        }

        const ClientTransport * m_ClientTransport_p = nullptr;
        std::string m_server_name;
        uint32_t m_port_number;
        bool m_is_connected;
        
};
#endif
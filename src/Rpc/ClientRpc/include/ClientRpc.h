#ifndef CLIENT_RPC_H
#define CLIENT_RPC_H



namespace Rpc {

    class ClientRpc {

        public:
            virtual ~ClientRpc();
            virtual bool connect(const std::string, const int) = 0;
            virtual bool disconnect(void) = 0;
            virtual std::string callRemoteFunction(const std::string &funcName, Typename... args) = 0;
        
        private:

            ClientRpc();
            
    };

}

#endif
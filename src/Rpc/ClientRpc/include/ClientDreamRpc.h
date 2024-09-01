namespace Rpc {

    class ClientDreamRpc : public ClientRpc{

        protected:
            ClientDreamRpc(const ClientTransport *ClientTransport_p): m_ClientTransport_p(ClientTransport_p) {
            
            }

            static ClientDreamRpc* m_ClientDreamRpc_p;

        public:
            ~ClientDreamRpc();
            bool connect(const std::string, const int) override;
            bool disconnect(void) override;
            std::string callRemoteFunction(const std::string &funcName, Typename... args) override;

            ClientDreamRpc(ClientDreamRpc &other) = delete;
            void operator=(const ClientDreamRpc &) = delete;

            static ClientDreamRpc *GetInstance(const std::string& value);
        private:
            ClientTransport * m_ClientTransport_p;
            
            
    };

}

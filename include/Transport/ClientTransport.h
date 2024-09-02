#ifndef CLIENT_TRANSPORT_H
#define CLIENT_TRANSPORT_H

class ClientTransport {
    public:
        ClientTransport(void) {
        }
        virtual ~ClientTransport() {
        }
        virtual void connect(const std::string server_name, const int port_number) = 0;
        virtual void sendRequest(const std::string & data) = 0;
    private:
};

#endif
#ifndef CLIENT_TRANSPORT_H
#define CLIENT_TRANSPORT_H

class ClientTransportInterface {
    public:
        ClientTransportInterface(void) {
        }
        virtual ~ClientTransportInterface() {
        }
        virtual void connect(const std::string server_name, const int port_number) = 0;
        virtual void sendRequest(const std::string & data) = 0;
    private:
};

#endif
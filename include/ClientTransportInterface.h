#ifndef CLIENT_TRANSPORT_H
#define CLIENT_TRANSPORT_H

#include <string>

using namespace std;

class ClientTransportInterface {
    public:
        ClientTransportInterface(void) {
        }
        virtual ~ClientTransportInterface() {
        }
        virtual void connect(const std::string server_name, const int port_number) = 0;
        virtual void disconnect(void) = 0;
        virtual void sendRequest(const std::string & data) = 0;
        virtual std::string handleResponse(void) = 0;
    private:
};

#endif
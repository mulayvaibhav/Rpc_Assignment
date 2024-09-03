#ifndef SERVER_TRANSPORT_H
#define SERVER_TRANSPORT_H

#include <string>

using namespace std;

class ServerTransportInterface {
    public:
        ServerTransportInterface(void) {
        }
        virtual ~ServerTransportInterface() {
        }
        virtual void connect(const std::string &server_name, const int port_number) = 0;
        virtual void reply(void) = 0;
        virtual const std::string sendResponse(const std::string &data) = 0;
        virtual const std::string handleRequest(const std::string &data) = 0;
    private:
};

#endif
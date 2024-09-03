#ifndef SERVER_TRANSPORT_BADDREAM_HTTP_H
#define SERVER_TRANSPORT_BADDREAM_HTTP_H

#include <ServerTransportInterface.h>
#include <iostream>

using namespace std;


class ServerBadDreamHTTP : public ServerTransportInterface {

    public:
        ServerBadDreamHTTP(void) {

        }

        ~ServerBadDreamHTTP() {

        }

        inline void connect(const std::string &server_name, const int port_number) {
            m_server_name = server_name;
            m_port_number = port_number;
        }
        inline void reply(void) {
            
        }
        inline const std::string sendResponse(const std::string &data) { return data; }
        inline const  std::string handleRequest(const std::string &data) { return data; }

    private:
        std::string m_server_name;
        int m_port_number;
};


#endif
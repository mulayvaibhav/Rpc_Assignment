#ifndef CLIENT_TRANSPORT_BADDREAM_HTTP_H
#define CLIENT_TRANSPORT_BADDREAM_HTTP_H

#include <ClientTransport.h>
#include <iostream>

using namespace std;


class ClientBadDreamHTTP : public ClientTransport {

    public:
        ClientBadDreamHTTP(void);

        ~ClientBadDreamHTTP() {

        }
        void connect(const std::string server_name, const int port_number);
        void sendRequest(const std::string & data);
    
    private:
        std::string m_server_name;
        std::string m_port_number;
};


#endif
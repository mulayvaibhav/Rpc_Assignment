#ifndef SERVER_ABTRACT_FACTORY_H
#define SERVER_ABTRACT_FACTORY_H

using namespace std;

#include <ServerTransportInterface.h>
#include <ServerRpcInterface.h>

class ServerAbstractFactoryInterface {

    public:
        ServerAbstractFactoryInterface() {

        }

        virtual ~ServerAbstractFactoryInterface() {

        }
        virtual ServerTransportInterface * CreateServerTransport(void) = 0;
        virtual ServerRpcInterface * CreateServerRpc(ServerTransportInterface *) = 0;

};


#endif
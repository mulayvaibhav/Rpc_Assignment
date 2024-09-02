#ifndef CLIENT_ABTRACT_FACTORY_H
#define CLIENT_ABTRACT_FACTORY_H

using namespace std;

#include <ClientTransportInterface.h>
#include <ClientRpcInterface.h>

class ClientAbstractFactoryInterface {

    public:
        ClientAbstractFactoryInterface() {

        }

        virtual ~ClientAbstractFactoryInterface() {

        }
        virtual ClientTransportInterface * CreateClientTransport(void) = 0;
        virtual ClientRpcInterface * CreateClientRpc(ClientTransportInterface *) = 0;

};


#endif
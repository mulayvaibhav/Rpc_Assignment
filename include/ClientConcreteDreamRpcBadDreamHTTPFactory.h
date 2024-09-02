#ifndef CLIENT_DREAM_RPC_BAD_DREAM_HTTP_FACTORY_H
#define CLIENT_DREAM_RPC_BAD_DREAM_HTTP_FACTORY_H

using namespace std;

#include <ClientAbstractFactoryInterface.h>

class ClientConcreteDreamRpcBadDreamHTTPFactory : public ClientAbstractFactoryInterface {

    public:
        ClientConcreteDreamRpcBadDreamHTTPFactory() {
            
        }
        ClientTransportInterface * CreateClientTransport(void);
        ClientRpcInterface * CreateClientRpc(ClientTransportInterface *);

};


#endif
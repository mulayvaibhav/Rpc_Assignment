#ifndef SERVER_DREAM_RPC_BAD_DREAM_HTTP_FACTORY_H
#define SERVER_DREAM_RPC_BAD_DREAM_HTTP_FACTORY_H

using namespace std;

#include <ServerAbstractFactoryInterface.h>

class ServerConcreteDreamRpcBadDreamHTTPFactory : public ServerAbstractFactoryInterface {

    public:
        ServerConcreteDreamRpcBadDreamHTTPFactory() {
            
        }
        
        ~ServerConcreteDreamRpcBadDreamHTTPFactory() {

        }
        ServerTransportInterface * CreateServerTransport(void);
        ServerRpcInterface * CreateServerRpc(ServerTransportInterface *);
};


#endif
#include <iostream>
#include <stdio.h>
#include <vector>
#include <unistd.h>

#include <ClientRpcInterface.h>
#include <ClientTransportInterface.h>
#include <ClientBadDreamHTTP.h>
#include <ClientDreamRpc.h>
#include <ClientConcreteDreamRpcBadDreamHTTPFactory.h>


using namespace std;

int main()
{
    
    ClientAbstractFactoryInterface * clientFactory_p = new ClientConcreteDreamRpcBadDreamHTTPFactory();
    if(clientFactory_p == nullptr) {
        cout << "failed to create client factory "<< endl;

        return 0;
    }

    /* BadDreamHTTP object creation */
    ClientTransportInterface * clientHTTPTransport_p = clientFactory_p->CreateClientTransport();
    
    /* DreamRPC object creatrion */
    ClientRpcInterface * clientDreamRpc_p = clientFactory_p->CreateClientRpc(clientHTTPTransport_p);
    if(clientDreamRpc_p == nullptr) {
        cout << "failed to start the Client RPC "<< endl;

        return 0;
    }

    clientDreamRpc_p->connect("https://google.com", 9090);
    clientDreamRpc_p->callRemoteFunction("hello");
    sleep(1);
    clientDreamRpc_p->handleResponse("");

    while(1) {

    }

}
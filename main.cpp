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
    
    cout<<"    Starting communication..." << endl << endl;

    int x = 10;
    while(--x) {
        clientDreamRpc_p->callRemoteFunction("hello");
        sleep(1);
        cout<<clientDreamRpc_p->handleResponse("")<<endl;
        cout<<endl;
        clientDreamRpc_p->callRemoteFunction("add", 100, 200);
        sleep(1);
        cout<<clientDreamRpc_p->handleResponse("")<<endl;
        cout<<endl;
    }

}
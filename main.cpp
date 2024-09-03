#include <iostream>
#include <stdio.h>
#include <vector>
#include <unistd.h>

#include <ClientRpcInterface.h>
#include <ClientTransportInterface.h>
#include <ClientBadDreamHTTP.h>
#include <ClientDreamRpc.h>
#include <ClientConcreteDreamRpcBadDreamHTTPFactory.h>

#include <ServerRpcInterface.h>
#include <ServerTransportInterface.h>
#include <ServerBadDreamHTTP.h>
#include <ServerDreamRpc.h>
#include <ServerConcreteDreamRpcBadDreamHTTPFactory.h>

using namespace std;

int main()
{
    /* Client Concrete factory creation */   
    ClientAbstractFactoryInterface * clientFactory_p = new ClientConcreteDreamRpcBadDreamHTTPFactory();
    if(clientFactory_p == nullptr) {
        cout << "failed to create client concrete factory "<< endl;

        return 0;
    }

    /* Server Concrete factory creation */
    ServerAbstractFactoryInterface * serverFactory_p = new ServerConcreteDreamRpcBadDreamHTTPFactory();
    if(serverFactory_p == nullptr) {
        cout << "failed to create server concrete factory "<< endl;

        return 0;
    }

    /* Client BadDreamHTTP object creation */
    ClientTransportInterface * clientHTTPTransport_p = clientFactory_p->CreateClientTransport();
    if(clientHTTPTransport_p == nullptr) {
        cout << "failed to start the Client concrete BadDream HTTP "<< endl;

        return 0;
    }
    /* Client DreamRPC object creatrion */
    ClientRpcInterface * clientDreamRpc_p = clientFactory_p->CreateClientRpc(clientHTTPTransport_p);
    if(clientDreamRpc_p == nullptr) {
        cout << "failed to start the Client concrete RPC "<< endl;

        return 0;
    }

    /* Server BadDreamHTTP object creation */
    ServerTransportInterface * serverHTTPTransport_p = serverFactory_p->CreateServerTransport();
    if(serverHTTPTransport_p == nullptr) {
        cout << "failed to start the Server concrete BadDream HTTP "<< endl;
    }
    
    /* Server DreamRPC object creatrion */
    ServerRpcInterface * serverDreamRpc_p = serverFactory_p->CreateServerRpc(serverHTTPTransport_p);
    if(serverDreamRpc_p == nullptr) {
        cout << "failed to start the Server concrete RPC "<< endl;

        return 0;
    }

    clientDreamRpc_p->connect("https://google.com", 9090);
    cout<<"    Starting communication..." << endl << endl;

    int index = 5;
    int val1 = 100;
    int val2 = 200;

    while(--index) {
        clientDreamRpc_p->callRemoteFunction("hello");
        sleep(1);
        cout<<clientDreamRpc_p->handleResponse("")<<endl;
        cout<<endl;
        clientDreamRpc_p->callRemoteFunction("add", val1, val2);
        sleep(1);
        cout<<clientDreamRpc_p->handleResponse("")<<endl;
        cout<<endl;
        ++val1;
        ++val2;
    }

    cout << "... Remote calls done clsong connection!!! " << endl;
    cout << "... "<<endl;

    clientDreamRpc_p->disconnect();
    sleep(1);
}   
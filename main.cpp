#include <iostream>
#include <stdio.h>


#include <ClientRpc.h>
#include <ClientTransport.h>
#include <ClientBadDreamHTTP.h>
#include <ClientDreamRpc.h>

using namespace std;

int main()
{
    cout<<"Dream project" << endl;

    const ClientTransport * http_ptr = new ClientBadDreamHTTP();
    
    ClientRpc * ptr = ClientDreamRpc::GetInstance(http_ptr);

    if(ptr != nullptr) {
        cout<<" Yahoo!!" << endl;    
    }
}
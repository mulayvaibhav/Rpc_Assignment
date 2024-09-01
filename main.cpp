#include <iostream>
#include <stdio.h>


#include <ClientRpc.h>
#include <ClientTransport.h>
#include <ClientBadDreamHTTP.h>
#include <ClientDreamRpc.h>

using namespace std;

int main()
{
    const ClientTransport * http_ptr = new ClientBadDreamHTTP();
    
    ClientRpc * ptr = ClientDreamRpc::GetInstance(http_ptr);

    if(ptr != nullptr) {
        ptr->connect("https://google.com", 9090);  

        string func_name = "hello()";
        ClientDreamRpc * ch_ptr = dynamic_cast<ClientDreamRpc*>(ptr);
        if(ch_ptr != nullptr) {
            cout << ch_ptr->callRemoteFunction(func_name) << endl;

            func_name = "add";
            cout << ch_ptr->callRemoteFunction(func_name, 2, 7) << endl;
        }

        

    }


}
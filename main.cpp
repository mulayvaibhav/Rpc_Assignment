#include <iostream>
#include <stdio.h>
#include <vector>
#include <functional>

#include <ClientRpc.h>
#include <ClientTransport.h>
#include <ClientBadDreamHTTP.h>
#include <ClientDreamRpc.h>

using namespace std;

int main()
{
    ClientTransport * http_ptr = new ClientBadDreamHTTP();
    
    ClientRpc * ptr = ClientDreamRpc::GetInstance(http_ptr);

    if(ptr != nullptr) {
        ptr->connect("https://google.com", 9090);  

        string func_name("hello");
        //ClientDreamRpc * ch_ptr = dynamic_cast<ClientDreamRpc*>(ptr);
        //  int a = 0;
        if(ptr != nullptr) {
            //ClientDreamRpc::callRemoteFunction(func_name, a);

            //func_name = "add";
            //cout << ch_ptr->callRemoteFunction(func_name, 2, 7) << endl;


        }

        

    }


}
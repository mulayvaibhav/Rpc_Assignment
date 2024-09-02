/**
 * @file ClientDreamRpc.cpp
 *
 * @brief This is concrete implementarion for DreamRpc library
 *
 * @ingroup Rpc_Assignement
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Vaibhav Mulay
 * Contact: mulayvaibhav@gmail.com
 *
 */

#include <iostream>
#include <ClientDreamRpc.h>


using namespace std;

ClientDreamRpc * ClientDreamRpc::m_ClientDreamRpc_p= nullptr;

ClientDreamRpc::ClientDreamRpc(ClientTransport *ClientTransport_p): ClientRpc(ClientTransport_p), m_ClientTransport_p(ClientTransport_p) {
    cout << "-> Dream RPC Client instance created" << endl;
}

bool ClientDreamRpc::connect(const std::string server_name, const int port_number)
{
    cout <<"... Initiating connection on Server: "<< server_name << ", port no.: "<< port_number << endl;
    m_server_name = server_name;
    m_port_number = port_number;

    m_ClientTransport_p->connect(server_name, port_number);

    m_is_connected = true;


    return true;
}


bool ClientDreamRpc::disconnect()
{
    if(m_is_connected == true) {
        cout<<"... Disconnecting Server: "<< m_server_name << ", port no.: "<< m_port_number << endl;
    
        // Call Dream Rpc library 
    }
    
    return true;
}

std::string ClientDreamRpc::callRemoteFunction(const std::string &funcName, int arg1, int arg2)
{
    if(m_is_connected == true) {

        std::string requestData = funcName + "(" + std::to_string(arg1) + ", " + std::to_string(arg2) + ")";
        cout<<"-> Sending remote request" << endl;
        m_ClientTransport_p->sendRequest(requestData);
    }

    return "null";
}

ClientDreamRpc *ClientDreamRpc::GetInstance(ClientTransport * ptr)
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(m_ClientDreamRpc_p==nullptr){
        m_ClientDreamRpc_p = new ClientDreamRpc(ptr);
    }

    return m_ClientDreamRpc_p;
}
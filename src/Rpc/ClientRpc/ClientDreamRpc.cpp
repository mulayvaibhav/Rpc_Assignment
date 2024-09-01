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

#include <ClientDreamRpc.h>

ClientDreamRpc::ClientDreamRpc(const ClientTransport *ClientTransport_p) : ClientRpc(ClientTransport_p)
{
    m_ClientTransport_p = ClientTransport_p;
}

bool ClientDreamRpc::connect(const std::string server_name, const int port_number)
{
    cout<<"... Initiating connection on Server: "<< server_name << ", port no.: "<< port_number << endl;
    m_server_name = server_name;
    m_port_number = port_number;

    // Call Dream Rpc library 

    m_is_connected = true;
    cout<<"Connected..." << endl;

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

std::string ClientDreamRpc::callRemoteFunction(const std::string &funcName, Typename... args)
{
    if(m_is_connected == true) {
        
    }
}

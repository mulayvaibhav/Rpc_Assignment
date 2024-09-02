
/**
 * @file ClientBadDreamHTTP.cpp
 *
 * @brief This is concrete implementarion for BadDreamHTTP library
 *
 * @ingroup Rpc_Assignement
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Vaibhav Mulay
 * Contact: mulayvaibhav@gmail.com
 *
 */

#include <iostream>
#include <ClientBadDreamHTTP.h>

ClientBadDreamHTTP::ClientBadDreamHTTP(void)
{
    cout<<"ClientBadDreamHTTP instance created, initalizing HTTP instance on client...." << endl;
}

void ClientBadDreamHTTP::connect(const std::string server_name, const int port_number) 
{
    m_server_name = server_name;
    m_port_number = port_number;

    cout<<"ClientBadDreamHTTP: Initiating connection... " <<endl;
    cout<<"Connected to server: "<< m_server_name<<", port_number: "<<m_port_number << endl; 
}

void ClientBadDreamHTTP::sendRequest(const std::string & data) 
{
    cout<<"-> ClientBadDreamHTTP, Sending remote request, data: "<< data << endl;
}
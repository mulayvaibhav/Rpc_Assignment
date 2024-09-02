
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
#include <pthread.h>
#include <vector>
#include <sstream>

using namespace std;

std::string responseData = "";
std::string requestData = "";

pthread_t t1;

void * fake_server(void * fake) {

    while(1) {
        if (requestData.find("hello") != std::string::npos) {
            cout<<"received hello"<<endl;
            responseData = "Greetings";
            requestData = "";
        } 
        else if (requestData.find("add") != std::string::npos) {
            int arg1 = 0, arg2=0;

            size_t start = requestData.find('(');
            size_t end = requestData.find(')');

            // If the brackets are not found or in the wrong order, print an error and return
            if (start != std::string::npos && end != std::string::npos && start >= end) {

                // Extract the substring between the brackets
                std::string args = requestData.substr(start + 1, end - start - 1);

                // Use a stringstream to split the string by comma and convert to integers
                std::stringstream ss(args);
                std::string item;
                std::vector<int> arguments;

                while (std::getline(ss, item, ',')) {
                    // Remove any leading/trailing whitespace (not strictly necessary here)
                    item.erase(0, item.find_first_not_of(" \t"));
                    item.erase(item.find_last_not_of(" \t") + 1);

                    // Convert to integer and store in the arguments vector
                    arguments.push_back(std::stoi(item));
                }

                // Store the parsed integers in the provided integer variables
                if (arguments.size() == 2) {
                    arg1 = arguments[0];
                    arg2 = arguments[1];
                } else {
                    std::cerr << "Expected two arguments, but found: " << arguments.size() << std::endl;
                }
                int res = arg1+arg2;
                responseData = std::to_string(res);
            }

            requestData = "";
        }
    }

    return fake;
}

ClientBadDreamHTTP::ClientBadDreamHTTP(void)
{
    cout<<"... BadDreamHTTP instance created, initalizing HTTP on client side" << endl;
    //void * tret;

    pthread_create(&t1, NULL, fake_server, NULL);
    pthread_detach(t1);
}

void ClientBadDreamHTTP::connect(const std::string server_name, const int port_number) 
{
    m_server_name = server_name;
    m_port_number = port_number;

    cout <<"... trying to connect" << endl; 

    /* call HTTP library function to connect */

    cout <<"... connected to: " << server_name <<" : " << port_number << endl;
}

void ClientBadDreamHTTP::sendRequest(const std::string & data) 
{
    responseData = "";
    cout<<"... [ClientBadDreamHTTP] Sending remote request: "<< data << endl;
    requestData = data;
    /* fakes sending RPC data to server s*/
}

std::string ClientBadDreamHTTP::handleResponse(void)
{
    cout<< "handleresponse : " << responseData << endl;
    /* fakes below layers that gets response from server */
    if(responseData.length() != 0) {
        return responseData;
    }

    return "";
}

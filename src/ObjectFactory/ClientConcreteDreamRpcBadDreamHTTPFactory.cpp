/**
 * @file ClientConcreteDreamRpcBadDreamHTTPFactory.cpp
 *
 * @brief This is concrete factory for creating DreamRpc 
 * and BadDreamHTTP concrete objects
 *
 * @ingroup Rpc_Assignement
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Vaibhav Mulay
 * Contact: mulayvaibhav@gmail.com
 *
 */

#include <ClientConcreteDreamRpcBadDreamHTTPFactory.h>
#include <ClientTransportInterface.h>
#include <ClientRpcInterface.h>
#include <ClientBadDreamHTTP.h>
#include <ClientDreamRpc.h>

ClientTransportInterface * 
    ClientConcreteDreamRpcBadDreamHTTPFactory::CreateClientTransport(void)
{
    cout << "... [ClientConcreteDreamRpcBadDreamHTTPFactory] created " << endl;
    ClientTransportInterface * ptr = new ClientBadDreamHTTP();
    return ptr;
}

ClientRpcInterface *
    ClientConcreteDreamRpcBadDreamHTTPFactory::CreateClientRpc(ClientTransportInterface * clIntf_p)
{
    if(clIntf_p != nullptr) {
        return ClientDreamRpc::GetInstance(clIntf_p);
    }

    return nullptr;
}
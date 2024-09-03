/**
 * @file ServerConcreteDreamRpcBadDreamHTTPFactory.cpp
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

#include <ServerConcreteDreamRpcBadDreamHTTPFactory.h>
#include <ServerTransportInterface.h>
#include <ServerRpcInterface.h>
#include <ServerBadDreamHTTP.h>
#include <ServerDreamRpc.h>

ServerTransportInterface * 
    ServerConcreteDreamRpcBadDreamHTTPFactory::CreateServerTransport(void)
{
    cout << "... [ServerConcreteDreamRpcBadDreamHTTPFactory] created " << endl;
    ServerTransportInterface * ptr = new ServerBadDreamHTTP();
    return ptr;
}

ServerRpcInterface *
    ServerConcreteDreamRpcBadDreamHTTPFactory::CreateServerRpc(ServerTransportInterface * svrIntf_p)
{
    if(svrIntf_p != nullptr) {
        return ServerDreamRpc::GetInstance(svrIntf_p);
    }

    return nullptr;
}
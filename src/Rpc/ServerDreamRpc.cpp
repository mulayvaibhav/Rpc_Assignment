/**
 * @file ServerDreamRpc.cpp
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
#include <ServerDreamRpc.h>

using namespace std;

ServerDreamRpc * ServerDreamRpc::m_ServerDreamRpc_p = nullptr;

ServerDreamRpc::ServerDreamRpc(ServerTransportInterface *ServerTransport_p): 
                ServerRpcInterface(ServerTransport_p), 
                m_ServerTransport_p(ServerTransport_p) 
{
    cout << "... Dream RPC Server instance created" << endl;
}

ServerDreamRpc *ServerDreamRpc::GetInstance(ServerTransportInterface * ptr)
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if(m_ServerDreamRpc_p==nullptr){
        cout << "... [ServerDreamRpc] created " << endl;
        m_ServerDreamRpc_p = new ServerDreamRpc(ptr);
    }

    return m_ServerDreamRpc_p;
}

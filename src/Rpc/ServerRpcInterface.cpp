/**
 * @file ServerRpc.cpp
 *
 * @brief This is the interface class for Server RPC 
 *
 * @ingroup Rpc_Assignement
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Vaibhav Mulay
 * Contact: mulayvaibhav@gmail.com
 *
 */

#include <ServerRpcInterface.h>

ServerRpcInterface::ServerRpcInterface(ServerTransportInterface *ServerTransport_p) 
{
    m_ServerTransport_p = ServerTransport_p;
}

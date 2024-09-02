/**
 * @file ClientRpc.cpp
 *
 * @brief This is the interface class for client RPC 
 *
 * @ingroup Rpc_Assignement
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Vaibhav Mulay
 * Contact: mulayvaibhav@gmail.com
 *
 */

#include <ClientRpcInterface.h>

ClientRpcInterface::ClientRpcInterface(ClientTransportInterface *ClientTransport_p) 
{
    m_ClientTransport_p = ClientTransport_p;
}


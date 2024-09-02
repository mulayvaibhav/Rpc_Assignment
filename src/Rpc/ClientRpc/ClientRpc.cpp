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

#include <ClientRpc.h>



ClientRpc::ClientRpc(ClientTransport *ClientTransport_p) 
{
    m_ClientTransport_p = ClientTransport_p;
}


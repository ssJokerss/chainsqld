//------------------------------------------------------------------------------
/*
	Copyright (c) 2011-2013, OpenCoin, Inc.

	Permission to use, copy, modify, and/or distribute this software for any
	purpose with  or without fee is hereby granted,  provided that the above
	copyright notice and this permission notice appear in all copies.

	THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
	WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES OF
	MERCHANTABILITY  AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
	ANY SPECIAL,  DIRECT, INDIRECT,  OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
	WHATSOEVER  RESULTING  FROM LOSS OF USE, DATA OR PROFITS,  WHETHER IN AN
	ACTION OF CONTRACT, NEGLIGENCE  OR OTHER TORTIOUS ACTION, ARISING OUT OF
	OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

/**	Add this to get the @ref ripple_net module.

    @file ripple_net.cpp
    @ingroup ripple_net
*/

#include "ripple_net.h"

#include "../ripple_data/ripple_data.h"

#include "../websocketpp/src/logger/logger.hpp" // for ripple_LogWebSockets.cpp

// VFALCO: TODO, fix these warnings!
#ifdef _MSC_VER
//#pragma warning (push) // Causes spurious C4503 "decorated name exceeds maximum length"
#pragma warning (disable: 4018) // signed/unsigned mismatch
#pragma warning (disable: 4244) // conversion, possible loss of data
#pragma warning (disable: 4309) // truncation of constant value
#endif

#include "src/cpp/ripple/Application.h"

// This is for PeerDoor and WSDoor
// Generate DH for SSL connection.
static DH* handleTmpDh(SSL* ssl, int is_export, int iKeyLength)
{
// VFALCO: TODO, eliminate this horrendous dependency on theApp and Wallet
	return 512 == iKeyLength ? theApp->getWallet().getDh512() : theApp->getWallet().getDh1024();
}

#include "src/cpp/ripple/Suppression.cpp" // no log
#include "src/cpp/ripple/UniqueNodeList.cpp"

#include "src/cpp/ripple/SNTPClient.cpp"

#include "src/cpp/ripple/ConnectionPool.cpp"
#include "src/cpp/ripple/NetworkOPs.cpp"
#include "src/cpp/ripple/Peer.cpp"
#include "src/cpp/ripple/PeerDoor.cpp"
#include "src/cpp/ripple/WSDoor.cpp" // uses logging in WSConnection.h 

#include "sockets/ripple_LogWebsockets.cpp"

#ifdef _MSC_VER
//#pragma warning (pop)
#endif

// local includes
#include "Client.hpp"

namespace rawsockets
{
	// Todo - mv cl's into def constr.
	Client::Client()
	{
	}
	Client::~Client()
	{
	}

	void Client::Cl(int port, string msg, string hostname)
	{
		ClientSocket ClientSock;
		if(ClientSock.CSocket(port, hostname)) {
			ClientSock.SendMesg(msg);
		}
	}

}

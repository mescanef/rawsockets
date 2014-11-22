// local includes
#include "Client.hpp"

namespace rawsockets
{
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

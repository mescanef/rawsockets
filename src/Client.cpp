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

	void Client::SendMesg(const int port, const string msg, const string hostname)
	{
		ClientSocket Client;
		if(Client.Socket(port, hostname)) {
			Client.SendMesg(msg);
		}
	}
	 
}

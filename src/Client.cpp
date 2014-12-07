// local includes
#include "Client.hpp"

namespace rawsockets
{
	Client::Client(Logger& _log) : log(_log)
	{				
	}
	Client::~Client()
	{
	}

	void Client::SendMesg(const int port, const string& msg, const string& hostname) const
	{
		ClientSocket Client(log);
		if(Client.Socket(port, hostname)) {
			Client.SendMesg(msg);
		}
		Client.~ClientSocket();
	}
	 
}

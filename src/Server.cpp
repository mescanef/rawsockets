// local includes
#include "Server.hpp"

namespace rawsockets
{
	Server::Server()
	{
	}

	Server::~Server()
	{
	}

	void Server::RunServer(int port)
	{
		rawsockets::ServerSocket sock;
		sock.Daemonize(port);
		// loop it - do not stop daemon after data recieve
		while (true) {
			rawsockets::ServerSocket new_sock;
			if(sock.Accept(new_sock)) {
				sock.Logger(SUCCSOCKACCEPT);
				// recieve data
			}
			new_sock.~ServerSocket();
		}
		sock.Logger(DAEMONSTOPPED);
	}

}
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

	void Server::RunServer(const int port)
	{
		rawsockets::ServerSocket sock;
		sock.Daemonize(port);
		// loop it - do not stop daemon after data receive
		while (true) {
			rawsockets::ServerSocket new_sock;
			if(sock.Accept(new_sock)) {
				sock.Logger(SUCCSOCKACCEPT);
				// receive message
				new_sock.RecvMesg();				
			}
			new_sock.~ServerSocket();
		}
		sock.Logger(DAEMONSTOPPED);
	}

}
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

	void Server::RunServer(const int port, Logger& log) const
	{
		ServerSocket sock(log);
		sock.Daemonize(port);
		// loop it - do not stop daemon after data receive
		while (true) {
			ServerSocket new_sock(log);
			if(sock.Accept(new_sock)) {
				log.Log(SUCCSOCKACCEPT);
				// receive message
				new_sock.RecvMesg();				
			}
			new_sock.~ServerSocket();
		}
		log.Log(DAEMONSTOPPED);
		sock.~ServerSocket();
	}

}
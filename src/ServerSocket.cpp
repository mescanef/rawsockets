// local includes
#include "ServerSocket.hpp"

namespace rawsockets
{
	ServerSocket::ServerSocket()
	{
	}

	ServerSocket::~ServerSocket()
	{
	}

	void ServerSocket::Daemonize(int port)
	{
		if (!SocketClass::Create()) {
			Logger("Could not create server socket.");
		} else {
			if (!SocketClass::Bind(port)) {
				Logger("Could not bind to port.");
			} else {
				if (!SocketClass::Listen()) {
					Logger("Could not listen to socket.");
				} else {
					Logger("Daemon started!");
				}
			}
		}
	}

	bool ServerSocket::Accept(ServerSocket& sock)
	{
		if (!SocketClass::Accept(sock)) {
			Logger("Could not accept socket.");
			return false;
		}
		return true;
	}

	void ServerSocket::Logger(string text)
	{
		ofstream log_file("server.log", ios_base::out | ios_base::app);
		log_file << text << endl;
	}
}

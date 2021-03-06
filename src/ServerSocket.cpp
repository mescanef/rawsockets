// local includes
#include "ServerSocket.hpp"

namespace rawsockets
{
	ServerSocket::ServerSocket(Logger& _log) : log(_log)
	{	
	}

	ServerSocket::~ServerSocket()
	{
	}

	void ServerSocket::Daemonize(const int port)
	{
		if (!SocketClass::Create()) {
			log.Log(ERRSOCKCREATE);
		} else {
			if (!SocketClass::Bind(port)) {
				log.Log(ERRSOCKBIND);
			} else {
				if (!SocketClass::Listen()) {
					log.Log(ERRSOCKLISTEN);
				} else {
					log.Log(DAEMONSTARTED);
				}
			}
		}
	}

	bool ServerSocket::Accept(ServerSocket& sock) const
	{
		if (!SocketClass::Accept(sock)) {
			log.Log(ERRSOCKACCEPT);
			return false;
		}
		return true;
	}

	void ServerSocket::RecvMesg() const
	{
		string msg;
		if (!SocketClass::RecvMesg(msg)) {
			log.Log(ERRSOCKRECVMSG);
		}
		else
		{
			log.Log(MSGRECEIVED + msg);
			cout << MSGRECEIVED << msg << endl;
		}
	}
}

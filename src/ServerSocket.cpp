// local includes
#include "ServerSocket.hpp"

using std::cout;
using std::endl;

namespace rawsockets
{
	ServerSocket::ServerSocket()
	{
	}

	ServerSocket::~ServerSocket()
	{
	}

	void ServerSocket::Daemonize(const int port)
	{
		if (!SocketClass::Create()) {
			Logger(ERRSOCKCREATE);
		} else {
			if (!SocketClass::Bind(port)) {
				Logger(ERRSOCKBIND);
			} else {
				if (!SocketClass::Listen()) {
					Logger(ERRSOCKLISTEN);
				} else {
					Logger(DAEMONSTARTED);
				}
			}
		}
	}

	bool ServerSocket::Accept(ServerSocket& sock)
	{
		if (!SocketClass::Accept(sock)) {
			Logger(ERRSOCKACCEPT);
			return false;
		}
		return true;
	}

	void ServerSocket::RecvMesg()
	{
		string msg;
		if (!SocketClass::RecvMesg(msg)) {
			Logger(ERRSOCKRECVMSG);
		}
		else
		{
			Logger("Server: Received from client: " + msg);
			cout << "Server: Received from client: " << msg << endl;
		}
	}

	void ServerSocket::Logger(const string text)
	{
		ofstream log_file(LOGFILENAME, ios_base::out | ios_base::app);
		log_file << text << endl;
	}
}

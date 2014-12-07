// local includes
#include "ClientSocket.hpp"

namespace rawsockets
{
	ClientSocket::ClientSocket(Logger& _log) : log(_log)
	{
	}
		
	ClientSocket::~ClientSocket()
	{
	}

	bool ClientSocket::Socket(const int port, const string& host) 
	{
		cout << "Connecting to " << host << ":" << port << endl;
		if (!SocketClass::Create()) {
			log.Log(ERRSOCKCREATE);
			return false;
		}
		if (!SocketClass::Connect(host, port)) {
			cout << ERRSOCKCONNECT << endl;
			log.Log(ERRSOCKCONNECT);
			return false;
		}
		cout << SUCCSOCKCONNMSG << endl;
		log.Log(SUCCSOCKCONNMSG);
		return true;
	}

	// send string to the server
	void ClientSocket::SendMesg(const string& s) const
	{
		if (!SocketClass::SendMesg(s)) {
			cout << ERRSOCKSENDMSG << endl;
			log.Log(ERRSOCKSENDMSG);
		}
	}
}

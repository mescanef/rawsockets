// local includes
#include "ClientSocket.hpp"

namespace rawsockets
{
	ClientSocket::ClientSocket()
	{
	}
		
	ClientSocket::~ClientSocket()
	{
	}

	bool ClientSocket::Socket(const int port, const string host)
	{
		cout << "Connecting to " << host << ":" << port << endl;
		if (!SocketClass::Create()) {
			Logger(ERRSOCKCREATE);
			return false;
		}
		if (!SocketClass::Connect(host, port)) {
			cout << ERRSOCKCONNECT << endl;
			Logger(ERRSOCKCONNECT);
			return false;
		}
		cout << SUCCSOCKCONNMSG << endl;
		Logger(SUCCSOCKCONNMSG);
		return true;
	}

	// send string to the server
	void ClientSocket::SendMesg(const string s)
	{
		if (!SocketClass::SendMesg(s)) {
			cout << ERRSOCKSENDMSG << endl;
			Logger(ERRSOCKSENDMSG);
		}
	}

	// TODO: add timestamps, remove newlines....
	void ClientSocket::Logger(const string text)
	{
		ofstream log_file(LOGFILENAME, ios_base::out | ios_base::app);
		log_file << text << endl;
	}
}

// local includes
#include "ClientSocket.hpp"

namespace rawsockets
{
	ClientSocket::~ClientSocket()
	{
	}
	ClientSocket::ClientSocket()
	{
	}

	bool ClientSocket::CSocket(int port)
	{
		cout << "Connecting to: " << LOCALHOST << ":" << port << "\n";
		if (!SocketClass::Create()) {
			Logger(ERRSOCKCREATE);
			return false;
		}
		if (!SocketClass::Connect(LOCALHOST, port)) {
			cout << ERRSOCKCONNECT;
			Logger(ERRSOCKCONNECT);
			return false;
		}
		cout << SUCCSOCKCONNMSG;
		Logger(SUCCSOCKCONNMSG);
		return true;
	}

	bool ClientSocket::CSocket(int port, string host)
	{
		cout << "Connecting to: " << host << " " << port << "\n";
		if (!SocketClass::Create()) {
			Logger(ERRSOCKCREATE);
			return false;
		}
		if (!SocketClass::Connect(host, port)) {
			cout << ERRSOCKCONNECT;
			Logger(ERRSOCKCONNECT);
			return false;
		}
		cout << SUCCSOCKCONNMSG;
		Logger(SUCCSOCKCONNMSG);
		return true;
	}

	// send string to the server
	void ClientSocket::SendMesg(string s)
	{
		if (!SocketClass::SendMesg(s)) {
			cout << ERRSOCKSENDMSG;
			Logger(ERRSOCKSENDMSG);
		}
	}
	
	// TODO: add timestamps, remove newlines....
	void ClientSocket::Logger(string text)
	{
		ofstream log_file("client.log", ios_base::out | ios_base::app);
		log_file << text << endl;
	}
}

#ifndef CLIENTSOCKET_HPP
#define CLIENTSOCKET_HPP

#define LOCALHOST "localhost"
#define ERRSOCKCREATE "Sorry, Could not create client socket.\n"
#define ERRSOCKCONNECT "Sorry. Unable to connect!\n"
#define ERRSOCKSENDMSG "Sorry. Could not send message!\n"
#define SUCCSOCKCONNMSG "Connected!\n"

// global includes
#include <string>
#include <fstream>
#include <iostream>
// local includes
#include "SocketClass.hpp"

using std::string;
using std::ofstream;
using std::ios_base;
using std::endl;
using std::cout;

namespace rawsockets
{
	class ClientSocket : private SocketClass
	{
	public:
		ClientSocket();
		~ClientSocket();
		// port
		bool CSocket(int);
		// port, hostname. Get overloaded.
		bool CSocket(int, string);
		void Logger(string);
		void SendMesg(string);
	};

}

#endif // CLIENTSOCKET_HPP

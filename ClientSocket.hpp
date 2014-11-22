#ifndef CLIENTSOCKET_HPP
#define CLIENTSOCKET_HPP

// global includes
#include <string>
#include <iostream>
// local includes
#include "SocketClass.hpp"
#include "Defines.hpp"

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
		// port, hostname 
		bool CSocket(int, string);
		void Logger(string);
		void SendMesg(string);
	};
}

#endif // CLIENTSOCKET_HPP

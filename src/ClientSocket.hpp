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
		// Todo - mv csocket's into def constr.
		ClientSocket();
		~ClientSocket();
		// port, hostname 
		bool Socket(const int, const string);
		void Logger(const string);
		void SendMesg(const string);
	};
}

#endif // CLIENTSOCKET_HPP

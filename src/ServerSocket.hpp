#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

// global includes
#include <string>
#include <fstream>
#include <iostream>
// local includes
#include "SocketClass.hpp"
#include "Defines.hpp"

using std::string;
using std::ofstream;
using std::ios_base;
using std::endl;

namespace rawsockets
{
	class ServerSocket : private SocketClass
	{
	public:
		ServerSocket();		
		~ServerSocket();
		void Daemonize(const int);
		bool Accept(ServerSocket&) const;
		void Logger(const string);
		void RecvMesg();
	};
}

#endif // SERVERSOCKET_HPP

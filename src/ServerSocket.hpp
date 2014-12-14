#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

// global includes
#include <string>
#include <iostream>
// local includes
#include "SocketClass.hpp"
#include "Defines.hpp"
#include "Logger.hpp"

using std::string;
using std::ofstream;
using std::ios_base;
using std::endl;
using std::to_string;
using std::cout;

namespace rawsockets
{
	class ServerSocket : private SocketClass
	{
	public:
		ServerSocket(Logger&);		
		~ServerSocket();
		void Daemonize(const int);
		bool Accept(ServerSocket&) const;
		void RecvMesg() const;
	private:
		Logger& log;
	};
}

#endif // SERVERSOCKET_HPP

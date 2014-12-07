#ifndef SERVER_HPP
#define SERVER_HPP

// global includes
#include <iostream>
// local includes
#include "ServerSocket.hpp"
#include "Logger.hpp"
 
namespace rawsockets
{
	class Server
	{
	public:
		Server();
		~Server();
		void RunServer(const int,Logger&) const;
	};
}

#endif // SERVER_HPP

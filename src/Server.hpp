#ifndef SERVER_HPP
#define SERVER_HPP

// global includes
#include <iostream>
// local includes
#include "ServerSocket.hpp"
 
namespace rawsockets
{
	class Server
	{
	public:
		Server();
		~Server();
		void RunServer(int);
	};
}

#endif // SERVER_HPP

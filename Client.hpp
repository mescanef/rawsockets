#ifndef CLIENT_HPP
#define CLIENT_HPP

// global includes
#include <iostream>
// local includes
#include "ClientSocket.hpp"

namespace rawsockets
{
	class Client
	{
	public:
		Client();
		~Client();
		// port, msg, host (optional)
		void Cl(int, string,string);
	};
}

#endif // CLIENT_HPP

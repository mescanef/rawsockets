#ifndef CLIENT_HPP
#define CLIENT_HPP

// local includes
#include "ClientSocket.hpp"

namespace rawsockets
{
	class Client
	{
	public:
		Client();
		~Client();
		// port, msg, host 
		void Cl(int, string,string);
	};
}

#endif // CLIENT_HPP

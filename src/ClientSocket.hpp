#ifndef CLIENTSOCKET_HPP
#define CLIENTSOCKET_HPP

// global includes
#include <string>
#include <iostream>
// local includes
#include "SocketClass.hpp"
#include "Defines.hpp"
#include "Logger.hpp"

using std::string;
using std::endl;
using std::cout;

namespace rawsockets
{
	class ClientSocket : private SocketClass
	{
	public:
		// Todo - mv csocket's into def constr.
		ClientSocket(Logger&);
		~ClientSocket();
		// port, hostname 
		bool Socket(const int, const string&);
		void SendMesg(const string&) const;
	private:
		Logger& log;
	};
}

#endif // CLIENTSOCKET_HPP

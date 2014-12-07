#ifndef CLIENT_HPP
#define CLIENT_HPP

// local includes
#include "ClientSocket.hpp"
#include "Logger.hpp"

namespace rawsockets
{
	class Client
	{
	public:
		Client(Logger&);
		~Client();
		// port, msg, host
		void SendMesg(const int, const string&, const string&) const;
	private:
		Logger& log;
	};
}

#endif // CLIENT_HPP

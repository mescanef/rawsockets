#ifndef SOCKETCLASS_HPP
#define SOCKETCLASS_HPP

// global includes
#include <cstring>
#include <netdb.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fstream>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
// local includes
#include "Defines.hpp"

using std::string;

namespace rawsockets
{
	class SocketClass
	{
	public:
		SocketClass();
		~SocketClass();

		// Server part
		bool Create();
		bool Bind(const int port);
		bool Listen() const;
		bool Accept(SocketClass&) const;
		bool RecvMesg(string&);

		// Client part
		bool Connect(const string host, const int port);
		bool SendMesg(string);
		void SetNonBlocking(const bool);

	private:
		int m_sock;
		sockaddr_in m_addr;
	};

}

#endif // SocketClass_HPP

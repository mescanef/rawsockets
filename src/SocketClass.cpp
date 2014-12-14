// local includes
#include "SocketClass.hpp"

namespace rawsockets
{
	SocketClass::SocketClass() : m_sock(-1)
	{
		memset(&m_addr, 0, sizeof (m_addr));
	}

	SocketClass::~SocketClass()
	{
	}

	bool SocketClass::Create()
	{
		m_sock = socket(AF_INET, SOCK_STREAM, 0);

		int on = 1;
		if (setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char*) &on, sizeof (on)) == -1) {
			return false;
		}
		return true;
	}

	bool SocketClass::Bind(const int port)
	{
		m_addr.sin_family = AF_INET;
		m_addr.sin_addr.s_addr = INADDR_ANY;
		m_addr.sin_port = htons(port);

		int bind_return = bind(m_sock, (struct sockaddr *) &m_addr, sizeof (m_addr));

		if (bind_return == -1) {
			return false;
		}
		return true;
	}

	bool SocketClass::Listen() const
	{
		int listen_return = listen(m_sock, MAXCONNS);
		if (listen_return == -1) {
			return false;
		}
		return true;
	}

	bool SocketClass::Accept(SocketClass& new_socket) const
	{
		int addr_length = sizeof (m_addr);
		new_socket.m_sock = accept(m_sock, (sockaddr *) & m_addr, (socklen_t *) & addr_length);

		if (new_socket.m_sock <= 0) {
			return false;
		}
		return true;
	}

	void SocketClass::SetNonBlocking(const bool var) const
	{
		int opts;

		opts = fcntl(m_sock, F_GETFL);

		if (opts < 0) {
			return;
		}

		if (var) {
			opts = (opts | O_NONBLOCK);
		} else {
			opts = (opts & ~O_NONBLOCK);
		}
		fcntl(m_sock, F_SETFL, opts);
	}

	bool SocketClass::Connect(const string& host, const int port)
	{
		m_addr.sin_family = AF_INET;
		m_addr.sin_port = htons(port);

		int status = inet_pton(AF_INET, host.c_str(), &m_addr.sin_addr);

		if (errno == EAFNOSUPPORT) return false;

		status = connect(m_sock, (sockaddr *) & m_addr, sizeof (m_addr));

		if (status == 0) {
			return true;
		} else {
			return false;
		}
	}

	bool SocketClass::SendMesg(const string& s) const
	{
		unsigned int msgLength = htonl(s.size());

		int status = send(m_sock, &msgLength, sizeof(msgLength), MSG_NOSIGNAL);
		if (status == -1) {
			return false;
		}

		status = send(m_sock, s.data(), s.size(), MSG_CONFIRM);
		if (status == -1) {
			return false;
		}
		return true;
	}

	bool SocketClass::RecvMesg(string& msg, unsigned int& len) const
	{
		char buf [MAXRECV];
		unsigned int bufLen = 0;
		unsigned int tLen = sizeof(buf);
		unsigned int tDataRecv = 0;
		int dataRecv = 0;

		// get msg len first.
		dataRecv = recv(m_sock,&bufLen,sizeof(bufLen),MSG_NOSIGNAL);
		// check length
		if (ntohl(bufLen)<=0 || dataRecv<0) {
			return false;
		}
		len = ntohl(bufLen);
		
		dataRecv = 0;
		
		// get msg:
		while (tLen != len) {
			// clear buffer per recv!
			memset(buf, 0, MAXRECV);
			dataRecv = recv(m_sock,&buf,tLen,MSG_NOSIGNAL);
			if(dataRecv <= 0) {
				break;
			} else {
				msg += buf;
				if(len-tDataRecv<tLen) {
					tLen = len-tDataRecv;
				}
			}
		}
		if (msg.size()>0) {
			return true;
		}
		return false;
	}
}

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
		Mesg mesg;		
		mesg.set_msg(s);
		
		uint32 msgLength = mesg.ByteSize();
		unsigned int prefixLength = sizeof(msgLength);
		int bufLength = prefixLength + msgLength;
		uint8 buf[bufLength];
		
		ArrayOutputStream arrayOut(buf, bufLength);
		CodedOutputStream codedOut(&arrayOut);
		
		codedOut.WriteLittleEndian32(msgLength);
		
		mesg.SerializeWithCachedSizes(&codedOut);
				
		int status = send(m_sock, buf, bufLength, MSG_NOSIGNAL);
		if (status != bufLength) {
			return false;		
		}

		return true;
	}

	bool SocketClass::RecvMesg(string& msg) const
	{
		Mesg mesg;
		
		uint32 msgLength;
		unsigned int prefixLength = sizeof(msgLength);
		uint8 prefix[prefixLength];
		
		// get msg len.
		if (prefixLength != recv(m_sock, prefix, prefixLength,MSG_NOSIGNAL)) {
			return false;
		}
	
		CodedInputStream::ReadLittleEndian32FromArray(prefix, &msgLength);
		uint8 buf[msgLength];
		
		// get msg.
		if (msgLength != recv(m_sock,buf,msgLength,MSG_NOSIGNAL)) 
		{
			return false;
		}
		
		ArrayInputStream arrayIn(buf, msgLength);
		CodedInputStream codedIn(&arrayIn);
		if (!mesg.ParseFromCodedStream(&codedIn)) {
			return false;
		}
		msg = mesg.DebugString();
		
		return true;
	}
}

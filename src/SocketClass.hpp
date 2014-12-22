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
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/message.h>
// local includes
#include "Defines.hpp"
#include "msg.pb.hpp"

using std::string;
using rawsockets::Mesg;
using google::protobuf::uint32;
using google::protobuf::uint8;
using google::protobuf::io::CodedInputStream;
using google::protobuf::io::ArrayOutputStream;
using google::protobuf::io::ArrayInputStream;
using google::protobuf::io::CodedOutputStream;
using google::protobuf::io::CodedInputStream;

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
		bool RecvMesg(string&) const;

		// Client part
		bool Connect(const string& host, const int port);
		bool SendMesg(const string&) const;
		void SetNonBlocking(const bool) const;

	private:
		int m_sock;
		sockaddr_in m_addr;
	};
}

#endif // SocketClass_HPP

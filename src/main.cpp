// global includes
#include <stdio.h>
#include <google/protobuf/message.h>
// local includes
#include "Server.hpp"
#include "Client.hpp"
#include "Defines.hpp"
#include "Logger.hpp"
#include "getoptpp/getopt_pp_standalone.h"

using std::cout;
using std::endl;
using GetOpt::GetOpt_pp;
using GetOpt::Option;
using rawsockets::Client;
using rawsockets::Server;
using rawsockets::Logger;
using google::protobuf::ShutdownProtobufLibrary;

int main(const int argc, const char **argv)
{
	// local vars
	unsigned int PORT=DEFPORT;
	string MODE=DEFMODE;
	string HOST=DEFHOST;
	string MESG=DEFMESG;
	
	// Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
	GOOGLE_PROTOBUF_VERIFY_VERSION;
			
	GetOpt_pp ops(argc, argv);

	// call logger def constr.
	Logger log;

	// get port value if specified in args..
	// TODO: non default port number shall be validated.
	ops >> Option('p',PORT);	

	if (ops >> Option('s', MODE)) {
		// run as server
		cout << "Running as server..." << endl;
		Server s;
		s.RunServer(PORT,log);
		s.~Server();
	} else {
		cout << "Running as a client..." << endl;
		// run as client by default
		// check if user provided a message - if not, then use variables' default
		ops >> Option('m', MESG);
		ops >> Option('h', HOST); // if user not specified hostname, then use variables' default
		Client c(log);
		c.SendMesg(PORT,MESG,HOST);
		c.~Client();
	}
	log.~Logger();
	ShutdownProtobufLibrary();

	return 0;
}

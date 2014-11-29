#include <stdio.h>
#include "Server.hpp"
#include "Client.hpp"
#include "Defines.hpp"
#include "getoptpp/getopt_pp_standalone.h"

// "private" vars
namespace pvars
{
	int MODE=DEFMODE;
	int PORT=DEFPORT;
	string HOST=DEFHOST;
	string MESG=DEFMESG;
}

using GetOpt::GetOpt_pp;
using GetOpt::Option;
using rawsockets::Client;
using rawsockets::Server;
using pvars::MODE;
using pvars::PORT;
using pvars::HOST;
using pvars::MESG;

int main(int argc, char **argv)
{
	GetOpt_pp ops(argc, argv);

	// get port value if specified in args..
	ops >> Option('p',PORT);

	if (ops >> Option('s', MODE)) {
		// run as server
		Server s;
		s.RunServer(PORT);
	} else {
		cout << "Running as a client.\n";
		// run as client by default
		// check if user provided a message - if not, then use variables' default		
		ops >> Option('m', MESG);
		ops >> Option('h', HOST); // if user not specified hostname, then use variables' default
		Client c;
		c.SendMesg(PORT,MESG,HOST);
	}
	return 0;
}

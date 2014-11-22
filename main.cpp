#include <stdio.h>
//#include "Server.hpp"
#include "Client.hpp"
#include "Defines.hpp"
#include "getoptpp/getopt_pp_standalone.h"

using std::endl;
using std::cout;
using GetOpt::GetOpt_pp;
using GetOpt::Option;
using rawsockets::Client;

namespace gvars
{
	int MODE=DEFMODE;
	int PORT=DEFPORT;
	string HOST=DEFHOST;
	string MESG=DEFMESG;
}

int main(int argc, char **argv)
{
	GetOpt_pp ops(argc, argv);

	// get port value if specified in args..
	ops >> Option('p',gvars::PORT);

	if (ops >> Option('s', gvars::MODE)) {
		// run as server
		// ......
	} else {
		cout << "Running as a client.\n";
		// run as client by default
		// check if user provided a message
		if(ops >> Option('m', gvars::MESG)) {
			Client c;
			ops >> Option('h', gvars::HOST); // if user not specified the hostname, then use variables' default
			c.Cl(gvars::PORT,gvars::MESG,gvars::HOST);
		} else {
			cout << "Sorry. No message specified. Exiting.\n";
		}

	}
	return 0;
}

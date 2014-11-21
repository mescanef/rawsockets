#include <stdio.h>
//#include "Server.hpp"
#include "Client.hpp"
#include "getoptpp/getopt_pp_standalone.h"

#define PORT 5555

using std::endl;
using std::cout;
using GetOpt::GetOpt_pp;
using GetOpt::Option;

int main(int argc, char **argv)
{
	int srvmode = 0;
	
	GetOpt_pp ops(argc, argv);
	
	if (ops >> Option('s', srvmode)) {
		// run as server
		// ......
	} else {
		cout << "Running as a client.\n"; 
		// run as client by default
		string hostname;
		string message;
		// check if user provided a message
		if(ops >> Option('m', message)) {
			rawsockets::Client c;
			if(ops >> Option('h', hostname)) {
				// user specified hostname to connect to.
				c.Cl(PORT,message,hostname);
			}
			else
			{
			// connect to loalhost
			c.Cl(PORT,message);
			}			
		}
		else
		{
			cout << "Sorry. No message specified. Exiting.\n"; 
		}
		
	}
	return 0;
}

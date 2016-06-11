// defines
#ifndef DEFHOST
#define DEFHOST "localhost"
#endif

#ifndef DEFPORT
#define DEFPORT 5555
#endif

#ifndef DEFMODE
#define DEFMODE "n"
#endif

#ifndef DEFMESG
#define DEFMESG "Hello, Doctor, Name, Continue, Yesterday, Tomorrow."
#endif

#ifndef ERRSOCKCREATE
#define ERRSOCKCREATE "Server: Sorry, Could not create socket."
#endif

#ifndef ERRSOCKCONNECT
#define ERRSOCKCONNECT "Client: Sorry. Unable to connect!"
#endif

#ifndef ERRSOCKSENDMSG
#define ERRSOCKSENDMSG "Client: Sorry. Could not send message!"
#endif

#ifndef SUCCSOCKCONNMSG
#define SUCCSOCKCONNMSG "Client: Connected!"
#endif

#ifndef ERRSOCKRECVMSG
#define ERRSOCKRECVMSG "Server: Sorry, could not receive message!"
#endif

#ifndef SUCCSOCKACCEPT 
#define SUCCSOCKACCEPT "Server: Socket accepted."
#endif

#ifndef ERRSOCKACCEPT 
#define ERRSOCKACCEPT "Server: Sorry, socket not accepted."
#endif

#ifndef ERRSOCKLISTEN
#define ERRSOCKLISTEN "Server: Could not listen to socket."
#endif

#ifndef DAEMONSTOPPED
#define DAEMONSTOPPED "Server: Daemon stopped."
#endif

#ifndef DAEMONSTARTED
#define DAEMONSTARTED "Server: Daemon started."
#endif

#ifndef ERRSOCKBIND
#define ERRSOCKBIND "Server: Could not bind to port."
#endif

#ifndef MAXCONNS
#define MAXCONNS 5
#endif

#ifndef MSGRECEIVED
#define MSGRECEIVED "Received from client "
#endif

#ifndef LOGFILENAME
#define LOGFILENAME "rawsockets.log"
#endif

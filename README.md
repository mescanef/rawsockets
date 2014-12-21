rawsockets
==========

Simple 'echo' client-server app written in C++.

This app, for data serialization, is using Google's Protobuf.

Usage
==========
To start in server mode:

$ ./rawsockets -s y

To run as a client:

$ ./rawsockets -m 'hello world!'

If server is using a different port than a default '5555', please specify the 'p' parameter - for instance:

$ ./rawsockets -p 9991 -m 'hello world!'


#ifndef _H_GURD_SOCKETSERVER
#define _H_GURD_SOCKETSERVER

#include "Socket.h"
using namespace std;

class SocketClient : public Socket
{

protected:

    struct sockaddr_in soc;
    
    int sock;
    
public:

    SocketServer(int port);
    
};



#endif /* _H_GURD_SOCKETSERVER */
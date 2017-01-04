#ifndef _H_GURD_SOCKETCLIENT
#define _H_GURD_SOCKETCLIENT

#include "Socket.h"
using namespace std;

class SocketClient : public Socket
{

protected:

    struct sockaddr_in soc;
    
    int sock;
    
public:

    SocketClient(string ip, int port);
    
};



#endif /* _H_GURD_SOCKETCLIENT */
#ifndef _H_GURD_SOCKET
#define _H_GURD_SOCKET

#include <string>
using namespace std;

class Socket
{

protected:

    struct sockaddr_in soc;
    
    int sock;
    
    Socket(){}

public:

    ~Socket();
    
    int Send(string data);
    
    string Recive();

};



#endif /* _H_GURD_SOCKET */
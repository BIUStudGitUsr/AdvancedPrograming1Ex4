
#include "SocketServer.h"

SocketServer::SocketServer(int port)
{
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&soc, 0, sizeof(soc));
    soc.sin_family = AF_INET;
    soc.sin_addr.s_addr = INADDR_ANY;
    soc.sin_port = htons(port);
    bind(sock, (struct sockaddr *)&soc, sizeof(soc));
}
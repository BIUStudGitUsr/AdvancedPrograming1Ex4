
#include "SocketClient.h"

SocketClient::SocketClient(string ip, int port)
{
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&soc, 0, sizeof(soc));
    soc.sin_family = AF_INET;
    soc.sin_addr.s_addr = inet_addr(ip);
    soc.sin_port = htons(port);
}
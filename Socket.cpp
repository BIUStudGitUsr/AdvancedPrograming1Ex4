
#include "Socket.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 524288

Socket::~Socket()
{
    close(sock);
}

int Socket::Send(string data)
{
    return sendto(sock, data.c_str(), data.length(), 0, (struct sockaddr *)&soc sizeof(soc));
}

string Socket::Recive()
{
    struct sockaddr_in from;
    char buffer[BUFFER_SIZE];
    int len = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &from, sizeof(from));
    soc = from;
    return string(buffer);
}
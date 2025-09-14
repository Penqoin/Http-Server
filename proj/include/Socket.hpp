#ifndef CLASS_SOCKET_HPP
#define CLASS_SOCKET_HPP

#include <netinet/in.h>
#include <cassert>
#include <sys/socket.h>
#include <unistd.h>
#include "iostream"

class Socket
{
private:
    int socketID;
    sockaddr_in settings;

public:
    Socket();
    ~Socket();

    void bind();
    void listen();
    void recieve();
    void connect();
    void send(const char* message);

    const int getID() const noexcept;

private:

};

#endif // !CLASS_SOCKET_HPP

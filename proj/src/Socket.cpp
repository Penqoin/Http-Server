#include "Socket.hpp"

Socket::Socket()
{
    this->socketID = socket(AF_INET, SOCK_STREAM, 0);
    assert(this->socketID != -1);

    this->settings.sin_family = AF_INET;
    this->settings.sin_port = htons(8080);
    this->settings.sin_addr.s_addr = INADDR_ANY;
}

Socket::~Socket()
{
    close(this->socketID);
}

void Socket::bind()
{
    int ret = ::bind(this->socketID,(struct sockaddr*)& this->settings, sizeof(this->settings));
    assert(ret != -1);
}

void Socket::listen()
{
    int ret = ::listen(this->socketID, 5);
    assert(ret != -1);

    int cli = accept(this->socketID, nullptr, nullptr);

    while (true)
    {
        char buffer[1024] = { 0 };

        recv(cli, buffer, sizeof(buffer), 0);
        std::cout << buffer << std::endl;
    }
}

void Socket::connect()
{
    int ret = ::connect(this->socketID, (struct sockaddr*)& this->settings, sizeof(this->settings));
    assert(ret != -1);
}

void Socket::send(const char* message)
{
    ::send(this->socketID, message, sizeof(message), 0);
}

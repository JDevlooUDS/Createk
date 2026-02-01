#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    const char * server_ip = "192.168.4.1";
    const int server_port = 1234;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return 1;
    }

    sockaddr_in server{};
}
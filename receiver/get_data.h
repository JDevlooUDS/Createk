#ifndef GET_DATA_H
#define GET_DATA_H

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int get_data()
{
    const char * server_ip = "192.168.4.1";
    const int server_port = 1234;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return -2;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0)
    {
        perror("Invalid address");
        close(sock);
        return -2;
    }

    if (connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return -2;
    }

    char buffer[16] = {0};
    ssize_t bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        perror("Receive failed");
        close(sock);
        return -2;
    }

    bool value = false;
    if (buffer[0] == '1' || strncmp(buffer, "true", 4) == 0) {
        value = true;
    }

    close(sock);
    return value;
}

#endif
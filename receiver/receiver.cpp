#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#include "get_data.h"

int main()
{
    while(true)
        std::cout << get_data() << std::endl;
}
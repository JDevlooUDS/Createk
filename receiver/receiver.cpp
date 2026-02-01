#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <stdlib.h>

#include "get_data.h"

#define REQUIRED_COUNTS 15

void action()
{
    system("aplay graou.wav");
}

int main()
{   
    const std::chrono::milliseconds COOLDOWN(60000);
    const std::chrono::milliseconds LOOP_DELAY(1000);

    int detectCount = 0;
    auto lastActionTime = std::chrono::steady_clock::time_point::min();

    while (true)
    {
        if (get_data() == 1)
        {
            detectCount++;
            if (detectCount > REQUIRED_COUNTS)
            {
                auto now = std::chrono::steady_clock::now();
                if (now - lastActionTime >= COOLDOWN)
                {
                    action();
                    lastActionTime = now;
                }

                detectCount = 0;
            }
        }
        else 
        {
            detectCount = 0;
        }
        std::this_thread::sleep_for(LOOP_DELAY);
    }

    return 0;
}
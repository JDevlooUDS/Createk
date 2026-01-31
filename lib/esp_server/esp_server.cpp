#include "esp_server.h"

WiFiServer server(1234);

void setup_server(const char ssid[MAX_STRING], const char password[MAX_STRING])
{
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    Serial.println(WiFi.softAPIP());

    server.begin();
}

void send_data(WiFiClient client)
{
    if (client)
    {
        Serial.println("\nClient Connected");

        while (client.connected())
        {
            bool data = is_animal();  
            client.print(data);
            delay(100);
        }
    }
}

bool is_animal()
{
    return true;
}
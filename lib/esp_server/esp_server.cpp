#include <Arduino.h>
#include "esp_server.h"
#include "HUSKYLENS.h"

HUSKYLENS huskyLens;

WiFiServer server(1234);

void setup_server(const char ssid[MAX_STRING], const char password[MAX_STRING])
{
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    Serial.println(WiFi.softAPIP());

    server.begin();
}

void setup_lens()
{
    Wire.begin(21,22);

    while (!huskyLens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        delay(100);
    }

    huskyLens.writeAlgorithm(ALGORITHM_OBJECT_RECOGNITION);
}

void send_data(WiFiClient client)
{
    if (client)
    {
        Serial.println("\nClient Connected");

        while (client.connected())
        {
            int data = is_animal();  
            client.print(data);
            delay(100);
        }
    }
}

int is_animal()
{
    if (!huskyLens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    if (huskyLens.available()) {
    HUSKYLENSResult result = huskyLens.read();
        if (result.ID == ID_PERSON) 
            return 1;
        return 0;
    }
    return -1;
}
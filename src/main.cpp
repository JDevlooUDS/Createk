#include <WiFi.h>
#include "esp_server.h"
#include "esp_client.h"


const char ssid[MAX_STRING] = "Banane12345";
const char password[MAX_STRING] = "12345678";

void setup() {
  Serial.begin(115200);
  setup_server(ssid, password);
}

void loop() {
  WiFiClient client = server.available();
  if (client)
  {
    send_data(client);
    client.stop();
  }
}

#ifndef MAX_STRING
#define MAX_STRING 20
#endif

#ifndef ESP_SERVER_H
#define ESP_SERVER_H

#include <WiFi.h>
#include <WiFiServer.h>
#include <WiFiClient.h>

extern WiFiServer server;

void setup_server(const char ssid[MAX_STRING], const char password[MAX_STRING]);
void send_data(WiFiClient client);
bool is_animal();

#endif
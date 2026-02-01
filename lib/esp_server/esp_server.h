#ifndef MAX_STRING
#define MAX_STRING 20
#endif

#ifndef ESP_SERVER_H
#define ESP_SERVER_H

#include <WiFi.h>
#include <WiFiServer.h>
#include <WiFiClient.h>
#include <Arduino.h>
#include "esp_server.h"
#include "HUSKYLENS.h"

#define ID_PERSON  1

extern WiFiServer server;

extern HUSKYLENS huskyLens;

void setup_server(const char ssid[MAX_STRING], const char password[MAX_STRING]);
void setup_lens();
void send_data(WiFiClient client);
int is_animal();

#endif
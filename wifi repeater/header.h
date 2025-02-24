#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <WiFi.h>

extern WiFiServer server;

bool connectWifi(const char *ssid, const char *password);
bool routerWifi(const char *ssid, const char *password);

#endif
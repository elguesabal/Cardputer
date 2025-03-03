#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <WiFi.h>
#include <WebServer.h>
#include <SPI.h>
#include <SD.h>

#define SSID "vampeta"              // NOME DA REDE WIFI
#define PASSWORD "12345678"         // SENHA DA REDE WIFI
#define SCK 40                      // SCK:G40
#define MISO 39                     // MISO:G39
#define MOSI 14                     // MOSI:G14
#define CS 12                       // CS:G12

extern WebServer webServer;

// ./cardputer.cpp
void cardputerStart(void);

// ./wifi.cpp
void acessPointerStart(void);

// ./server.cpp
void webServerStart(void);
void home(void);

// ./sd card.cpp
void sdStart(void);
String getPage(const char *path);

#endif
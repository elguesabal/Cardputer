#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <WiFi.h>
#include <WebServer.h>
#include <SPI.h>
#include <SD.h>

// #define M5CARDPUTER M5Cardputer.Display             // DISPLAY DO CARDPUTER (PODE REMOVER CASO NAO QUERIA Q O CARDPUTER INICIA A TELA)
#define SSID "vampeta"                              // NOME DA REDE WIFI
// #define PASSWORD "12345678"                      // SENHA DA REDE WIFI (PODE REMOVER CASO NAO QUERIA SENHA)
#define SCK 40                                      // SCK:G40
#define MISO 39                                     // MISO:G39
#define MOSI 14                                     // MOSI:G14
#define CS 12                                       // CS:G12
#define PATH_DIR "/Pages"                           // PASTA ONDE SE DEVE ENCONTRAR AS PAGINAS WEBS

extern WebServer webServer;

// ./cardputer.cpp
void cardputerStart(void);

// ./wifi.cpp
void acessPointerStart(void);

// ./webServer.cpp
void webServerStart(void);
void home(void);
String getType(String path);
void getRoute(void);

// ./sdCard.cpp
void sdStart(void);
File getFile(String path);

#endif
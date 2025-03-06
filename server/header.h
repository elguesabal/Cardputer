#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <WiFi.h>
#include <WebServer.h>
#include <SPI.h>
#include <SD.h>

#define M5CARDPUTER M5Cardputer.Display             // DISPLAY DO CARDPUTER (PODE REMOVER CASO NAO QUERIA QUE O CARDPUTER INICIA A TELA)
#define SSID "vampeta"                              // NOME DA REDE WIFI
// #define PASSWORD "12345678"                      // SENHA DA REDE WIFI (PODE REMOVER CASO NAO QUEIRA SENHA)
#define SCK 40                                      // SCK:G40
#define MISO 39                                     // MISO:G39
#define MOSI 14                                     // MOSI:G14
#define CS 12                                       // CS:G12

#define PORT_FRONT_END 80                           // PORTA ONDE O FRONT END VAI ESCUTAR AS REQUISICOES
#define PATH_FRONT_END "/Front-end"                 // PASTA ONDE SE DEVE ENCONTRAR OS ARQUIVOS FRONT END (PODE REMOVER CASO NAO QUEIRA FRONT END)
#define PORT_BACK_END 4242                          // PORTA ONDE O BACK END VAI ESCUTAR AS REQUISICOES
#define PATH_BACK_END "/Back-end"                   // PASTA ONDE SE DEVE ENCONTRAR OS ARQUIVOS BACK END (PODE REMOVER CASO NAO QUEIRA BACK END)

extern WebServer *frontEnd;
extern WebServer *backEnd;

// ./cardputer.cpp
void cardputerStart(void);

// ./wifi.cpp
void acessPointerStart(void);

// ./sdCard.cpp
void sdStart(void);
bool checkPath(const char *path);
File getFile(String path);

// ./front-end.cpp
void frontEndStart(void);
void home(void);
String getType(String path);
void getRoute(void);

// ./back-end.cpp
void backEndStart(void);

#endif
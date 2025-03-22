#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <WiFi.h>
#include <WebServer.h>

#define M5CARDPUTER M5Cardputer.Display             // DISPLAY DO CARDPUTER (PODE REMOVER CASO NAO QUERIA QUE O CARDPUTER INICIA A TELA)

#define SSID_WIFI "ELGUESABAL"                  // NOME DA REDE WIFI
#define PASSWORD_WIFI "12345678"                // SENHA DA REDE WIFI (PODE REMOVER CASO NAO EXIJA SENHA)

#define SSID_ACCESS_POINT "vampeta"             // NOME DO PONTO DE ACESSO CRIADO PELO CARDPUTER
#define PASSWORD_ACCESS_POINT "12345678"        // SENHA DO PONTO DE ACESSO (PODE REMOVER CASO NAO QUEIRA SENHA)

extern WebServer server;

// ./debug.cpp
void debugStart(void);

// ./display.cpp
void cardputerStart(void);
void vampeta(void);

// ./wifi.cpp
void connectWifi(void);

// ./access point.cpp
void accessPointStart(void);

// ./server.cpp
void serverStart(void);
void request(void);

#endif
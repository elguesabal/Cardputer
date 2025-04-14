#ifndef HEADER_H
#define HEADER_H

#include <M5Cardputer.h>
// #include <lwip/sockets.h>
// #include <lwip/netdb.h>

#include "WiFiCustom.h"
#include "dns.hpp"
#include "http.hpp"
#include "https.hpp"

#define M5CARDPUTER M5Cardputer.Display                          // DISPLAY DO CARDPUTER (PODE REMOVER CASO NAO QUERIA QUE O CARDPUTER INICIA A TELA)
#define SSID_WIFI "ELGUESABAL"                                   // NOME DO WIFI
#define PASSWORD_WIFI "12345678"                                 // SENHA DO WIFI (PODE REMOVER CASO NAO TENHA SENHA)
#define SSID_ACCESS_POINT "vampeta"                              // NOME DO ACCESS POINT
// #define PASSWORD_ACCESS_POINT "12345678"                      // SENHA DO ACCESS POINT (PODE REMOVER CASO NAO QUEIRA SENHA)
#define DNS_PORT 53                                              // PORTA DO DNS
#define HTTP_PORT 80                                             // PORTA HTTP
#define HTTPS_PORT 443                                           // PORTA HTTPS

// ./cardputer.cpp
void cardputerStart(void);
void vampeta(void);

// ./wifi.cpp
void wifiStart(void);

// ./access point.cpp
void acessPointerStart(void);

#endif
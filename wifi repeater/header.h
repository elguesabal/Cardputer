#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <WiFi.h>
#include <lwip/sockets.h>     // socket, bind, struct sockaddr_in etc.
#include <lwip/netdb.h>       // struct hostent, gethostbyname etc.
// #include <poll.h>             // pollfd (às vezes não está disponível em todas as toolchains do ESP)
#include "dns.h"

#define M5CARDPUTER M5Cardputer.Display                          // DISPLAY DO CARDPUTER (PODE REMOVER CASO NAO QUERIA QUE O CARDPUTER INICIA A TELA)
#define SSID_WIFI "ELGUESABAL"                                   // NOME DO WIFI
#define PASSWORD_WIFI "12345678"                                 // SENHA DO WIFI (PODE REMOVER CASO NAO TENHA SENHA)
#define SSID_ACCESS_POINT "vampeta"                              // NOME DO ACCESS POINT
// #define PASSWORD_ACCESS_POINT "12345678"                      // SENHA DO ACCESS POINT (PODE REMOVER CASO NAO QUEIRA SENHA)
#define DNS_PORT 53                                              // PORTA DO DNS

// ./cardputer.cpp
void cardputerStart(void);
void vampeta(void);

// ./wifi.cpp
void wifiStart(void);

// ./access point.cpp
void acessPointerStart(void);

#endif
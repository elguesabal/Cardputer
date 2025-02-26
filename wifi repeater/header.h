#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <WiFi.h>
#include <set>



// Definindo um comparador para WiFiClient
// struct WiFiClientCompare {
//     bool operator()(const WiFiClient& a, const WiFiClient& b) const {
//         if (a.remoteIP() != b.remoteIP()) {
//             return a.remoteIP() < b.remoteIP();  // Ordena pelo IP
//         }
//         return a.remotePort() < b.remotePort();  // Desempata pela porta
//     }
// };

// Criando um std::set com o comparador
// std::set<WiFiClient, WiFiClientCompare> clients;



extern WiFiServer server;

bool connectWifi(const char *ssid, const char *password);
bool routerWifi(const char *ssid, const char *password);

#endif
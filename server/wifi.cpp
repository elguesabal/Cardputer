#include "header.h"

/// @brief INICIA O PONTO DE ACESSO WIFI E PRINTA NA TELA O SSID E PASSWORD
void acessPointerStart(void) {
    WiFi.mode(WIFI_AP);
    #if defined(PASSWORD)
        bool wifi = WiFi.softAP(SSID, PASSWORD);
    #else
        bool wifi = WiFi.softAP(SSID);
    #endif
    if (!wifi) {
        M5Cardputer.Display.println("wifi nao criado");
        while (true) {

        }
    }
    M5Cardputer.Display.printf("Ssid: %s\n", SSID);
    #if defined(PASSWORD)
        M5Cardputer.Display.printf("Password: %s\n", PASSWORD);
    #endif
    M5Cardputer.Display.printf("Host: %s\n", WiFi.softAPIP().toString().c_str());
}



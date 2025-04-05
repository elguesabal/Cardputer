#include "header.h"

/// @brief INICIA O PONTO DE ACESSO WIFI E PRINTA NA TELA O SSID E PASSWORD
void acessPointerStart(void) {
    #if defined(PASSWORD_ACCESS_POINT)
        bool wifi = WiFi.softAP(SSID_ACCESS_POINT, PASSWORD_ACCESS_POINT);
    #else
        bool wifi = WiFi.softAP(SSID_ACCESS_POINT);
    #endif
    if (!wifi) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Access point nao criado");
        #endif
        while (true) {

        }
    }
    #if defined(M5CARDPUTER)
        M5CARDPUTER.println("Access point criado");
        M5CARDPUTER.printf("Ssid: %s\n", SSID_ACCESS_POINT);
        #if defined(PASSWORD_ACCESS_POINT)
            M5CARDPUTER.printf("Password: %s\n", PASSWORD_ACCESS_POINT);
        #endif
    #endif
}
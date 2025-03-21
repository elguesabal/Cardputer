#include "header.h"

/// @brief INICIA O PONTO DE ACESSO WIFI
void accessPointStart(void) {
    #if defined(PASSWORD_ACCESS_POINT)
        bool access_point = WiFi.softAP(SSID_ACCESS_POINT, PASSWORD_ACCESS_POINT);
    #else
        bool access_point = WiFi.softAP(SSID_ACCESS_POINT);
    #endif
    if (!access_point) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Falha na criacao no ponto de acesso");
        #endif
        return ;
    }
    #if defined(M5CARDPUTER)
        M5CARDPUTER.printf("Ponto de acesso criado: %s\n", SSID_ACCESS_POINT);
        #if defined(PASSWORD_ACCESS_POINT)
            M5CARDPUTER.printf("Senha do ponto de acesso: %s\n", PASSWORD_ACCESS_POINT);
        #endif
    #endif
}
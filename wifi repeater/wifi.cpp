#include "header.h"

/// @brief CONECTA A UMA REDE WIFI JA EXISTENTE
void connectWifi(void) {
    #if defined(PASSWORD_WIFI)
        WiFi.begin(SSID_WIFI, PASSWORD_WIFI);
    #else
        WiFi.begin(SSID_WIFI);
    #endif

    while (WiFi.status() != WL_CONNECTED && WiFi.status() != WL_NO_SSID_AVAIL && WiFi.status() != WL_CONNECT_FAILED) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("conectando...");
        #endif
        delay(1000);
    }

    #if defined(M5CARDPUTER)
        switch (WiFi.status()) {
            case WL_CONNECTED:
                M5CARDPUTER.printf("Conectado ao Wi-Fi: %s\n", SSID_WIFI);
                return ;
            case WL_NO_SSID_AVAIL:
                M5CARDPUTER.println("SSID não encontrado");
                return ;
            case WL_CONNECT_FAILED:
                M5CARDPUTER.println("Falha na conexão. Verifique a senha");
                return ;
            case WL_CONNECTION_LOST:
                M5CARDPUTER.println("Conexão perdida");
                return ;
            case WL_DISCONNECTED:
                M5CARDPUTER.println("Não conectado");
                return ;
            default:
                M5CARDPUTER.println("Status desconhecido");
                return ;
        }
    #endif
}
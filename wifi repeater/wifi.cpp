#include "header.h"

void wifiStart(void) {
    WiFi.mode(WIFI_AP_STA);
    #if defined(PASSWORD_WIFI)
        WiFi.begin(SSID_WIFI, PASSWORD_WIFI);
    #else
        WiFi.begin(SSID_WIFI);
    #endif
    while (WiFi.status() == WL_IDLE_STATUS) {
        delay(100);
    }
    delay(500);
    #if defined(M5CARDPUTER)
        switch (WiFi.status()) {
            case WL_NO_SSID_AVAIL:
                M5CARDPUTER.println("Wifi nao disponivel");
                break;
            case WL_CONNECTED:
                M5CARDPUTER.println("Wifi conectado");
                break;
            case WL_CONNECT_FAILED:
                M5CARDPUTER.println("Senha incorreta");
                break;
            case WL_DISCONNECTED:
                M5CARDPUTER.println("Desconectado");
                break;
            default:
                M5CARDPUTER.println("Status desconhecido");
        }
    #endif
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}
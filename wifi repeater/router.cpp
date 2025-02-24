#include "header.h"

bool routerWifi(const char *ssid, const char *password) {
    if (WiFi.softAP(ssid, password)) {
        M5Cardputer.Display.printf("Ponto de acesso criado: %s%c", WiFi.softAPIP().toString().c_str(), '\n');
        return (true);
    } else {
        M5Cardputer.Display.print("Falha na criacao do ponto de acesso");
        return (false);
    }
}
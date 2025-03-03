#include "header.h"

void acessPointerStart(void) {
    WiFi.mode(WIFI_AP);
    if (!WiFi.softAP(SSID, PASSWORD)) {
        M5Cardputer.Display.println("wifi nao criado");
        while (true) {

        }
    }
    M5Cardputer.Display.printf("Ssid: %s\n", SSID);
    M5Cardputer.Display.printf("Password: %s\n", PASSWORD);
    M5Cardputer.Display.printf("Host: %s\n", WiFi.softAPIP().toString().c_str());
}
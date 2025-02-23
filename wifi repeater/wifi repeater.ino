#include "header.h"

void print(std::string str) {
    M5Cardputer.Display.print(str.c_str());
}

bool connectWifi(const char *ssid, const char *password) {
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED && WiFi.status() != WL_NO_SSID_AVAIL && WiFi.status() != WL_CONNECT_FAILED) {
        print("conectando\n");
        delay(1000);
    }

    switch (WiFi.status()) {
        case WL_CONNECTED:
            print("Conectado ao Wi-Fi: ");
            // print(WiFi.localIP());
            print("\n");
            return (true);
        case WL_NO_SSID_AVAIL:
            print("SSID não encontrado\n");
            return (false);
        case WL_CONNECT_FAILED:
            print("Falha na conexão. Verifique a senha\n");
            return (false);
        case WL_CONNECTION_LOST:
            print("Conexão perdida\n");
            return (false);
        case WL_DISCONNECTED:
            print("Não conectado\n");
            return (false);
        default:
            print("Status desconhecido\n");
            return (false);
    }
}

void routerWifi(const char *ssid, const char *password) {
    WiFi.softAP(ssid, password);

}

void setup(void) {
    M5Cardputer.begin();

    WiFi.mode(WIFI_AP_STA);

    if (!connectWifi("ELGUESABAL", "12345678")) {
        return ;
    }
    routerWifi("vampeta", "12345678");
}

void loop(void) {

}

// void funcao(const std::string &str) {

// }

// funcao("a" + "b");
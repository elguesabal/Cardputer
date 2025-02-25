#include "header.h"

/// @brief CONECTA A UMA REDE WIFI JA EXISTENTE
/// @param ssid NOME DO WIFI
/// @param password SENHA DO WIFI
/// @return RETORNA true SE DEU TUDO CERTO E false SE OUVE ALGUM ERRO
bool connectWifi(const char *ssid, const char *password) {
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED && WiFi.status() != WL_NO_SSID_AVAIL && WiFi.status() != WL_CONNECT_FAILED) {
        M5Cardputer.Display.print("conectando\n");
        delay(1000);
    }

    switch (WiFi.status()) {
        case WL_CONNECTED:
            M5Cardputer.Display.printf("Conectado ao Wi-Fi: %s%c", WiFi.localIP().toString().c_str(), '\n');
            return (true);
        case WL_NO_SSID_AVAIL:
            M5Cardputer.Display.print("SSID não encontrado\n");
            return (false);
        case WL_CONNECT_FAILED:
            M5Cardputer.Display.print("Falha na conexão. Verifique a senha\n");
            return (false);
        case WL_CONNECTION_LOST:
            M5Cardputer.Display.print("Conexão perdida\n");
            return (false);
        case WL_DISCONNECTED:
            M5Cardputer.Display.print("Não conectado\n");
            return (false);
        default:
            M5Cardputer.Display.print("Status desconhecido\n");
            return (false);
    }
}
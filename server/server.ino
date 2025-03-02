// #include "header.h"

// DNSServer dnsServer;
// WebServer webServer(80);

// void setup(void) {
//     M5Cardputer.begin();
//     M5Cardputer.Display.setTextScroll(true);

//     WiFi.mode(WIFI_AP);
//     WiFi.softAP("vampeta", "12345678");
//     M5Cardputer.Display.printf("Ponto de acesso criado: %s\n", WiFi.softAPIP().toString().c_str());

//     dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());
//     webServer.on("/teste", []() {
//         M5Cardputer.Display.println("rota teste");
//         webServer.send(200, "text/html", "rota teste");
//     });
//     webServer.onNotFound([]() {
//         M5Cardputer.Display.println("rota nao encontrada");
//         webServer.send(200, "text/html", "rota nao encontrada");
//     });
//     webServer.begin();
// }

// void loop(void) {
//     dnsServer.processNextRequest();
//     webServer.handleClient();
// }




#include <M5Cardputer.h>
#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

// Configurar Ponto de Acesso
const char* ssid = "vampeta";
const char* password = "12345678";

WebServer server(80);
DNSServer dnsServer;
const byte DNS_PORT = 53;

void handleRoot() {
    server.send(200, "text/html", "<h1>Voce foi redirecionado para o M5Cardputer!</h1>");
}

void setup() {
    M5Cardputer.begin();
    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP();
    
    M5Cardputer.Display.setCursor(10, 10);
    M5Cardputer.Display.println("AP Criado!");
    M5Cardputer.Display.print("IP: ");
    M5Cardputer.Display.println(myIP);
    
    // Iniciar DNS para capturar todas as requisições
    dnsServer.start(DNS_PORT, "*", myIP);
    // dnsServer.start(DNS_PORT, "meusite.com", myIP);

    // Criar rota no servidor
    server.on("/", handleRoot);
    server.begin();
}

void loop() {
    server.handleClient();
    dnsServer.processNextRequest(); // Processa pedidos DNS
}

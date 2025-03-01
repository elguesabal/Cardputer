#include "header.h"

DNSServer dnsServer;
WebServer webServer(80);

void setup(void) {
    // START TELA
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
    // START TELA

    // START PONTO DE ACESSO WIFI
    WiFi.mode(WIFI_AP);
    // WiFi.softAPConfig(IPAddress(172, 0, 0, 1), IPAddress(172, 0, 0, 1), IPAddress(255, 255, 255, 0));
    WiFi.softAP("vampeta", "12345678");
    M5Cardputer.Display.printf("Ponto de acesso criado: %s\n", WiFi.softAPIP().toString().c_str());
    // START PONTO DE ACESSO WIFI

    // START SERVER
    dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());
    M5Cardputer.Display.println(WiFi.softAPIP());
    webServer.on("/teste", []() {
        M5Cardputer.Display.println("testando rota");
        String teste = "vampetaaaa";
        webServer.send(200, "text/html", teste);
    });
    webServer.onNotFound([]() {
        // M5Cardputer.Display.print("host: ");
        // M5Cardputer.Display.println(webServer.header("Host"));
        // String teste = "rota nao encontrada";
        // webServer.send(200, "text/html", teste);

        String host = webServer.header("Host"); // NAO TA FUNCIONANDO ???
        String response = "<h1>Bem-vindo ao M5Cardputer!</h1>";
        response += "<p>Você acessou: " + host + "</p>";
        
        webServer.send(200, "text/html", response);
    });
    webServer.begin();
    // START SERVER
}

void loop(void) {
    dnsServer.processNextRequest();
    webServer.handleClient();
}
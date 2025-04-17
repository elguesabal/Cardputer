#include <M5Cardputer.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WebServer.h>

WebServer server(80);

void handleRoot() {
    server.send(200, "text/html", "Vampeta");
}

void setup() {
    M5Cardputer.begin();

    WiFi.begin("jose", "04092023");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    M5Cardputer.Display.print("IP: ");
    M5Cardputer.Display.println(WiFi.localIP());
    M5Cardputer.Display.print("Hostname: ");
    M5Cardputer.Display.println(WiFi.getHostname());

    if (MDNS.begin("vampeta")) {
        M5Cardputer.Display.println("mDNS iniciado com sucesso!");
        M5Cardputer.Display.print("Acesse: http://");
        M5Cardputer.Display.print("vampeta");
        M5Cardputer.Display.println(".local");
    } else {
        M5Cardputer.Display.println("Erro ao iniciar mDNS");
    }

    server.on("/", handleRoot);
    server.begin();
    M5Cardputer.Display.println("Servidor HTTP iniciado");
}

void loop() {
    server.handleClient();
}
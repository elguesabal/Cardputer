#include <M5Cardputer.h>
#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

void page(void) {
    server.send(200, "text/html", "<h1>vampeta</h1>");
}

void setup(void) {
    M5Cardputer.begin();

    WiFi.begin("ELGUESABAL", "12345678");
    while (WiFi.status() != WL_CONNECTED) {
        M5Cardputer.Display.println("conectando");
        delay(1000);
    }

    M5Cardputer.Display.println("wifi conectado");
    M5Cardputer.Display.print("endereco ip: ");
    M5Cardputer.Display.println(WiFi.localIP());

    server.on("/", page);
    server.begin();
}

void loop(void) {
    server.handleClient();
}
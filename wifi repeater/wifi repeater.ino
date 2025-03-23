#include "header.h"

WebServer server(80);
DNSServer dnsServer;
// WiFiClient client;

void setup(void) {
    // debugStart();
    cardputerStart();
    connectWifi();
    accessPointStart();
    serverStart();
    dnsStart();


    // if (client.connect("google.com", 443)) {
    //     // Envia uma requisição HTTP GET
    //     client.println("GET / HTTP/1.1");
    //     client.println("Host: example.com");
    //     client.println("Connection: close");
    //     client.println(); // Linha em branco para indicar fim do cabeçalho
    // } else {
    //     M5CARDPUTER.println("Falha ao conectar ao servidor.");
    // }
}

void loop(void) {
    // while (client.available()) {
    //     Serial.println(client.readStringUntil('\n'));
    // }

    dnsServer.processNextRequest();
    server.handleClient();
    delay(2);
}
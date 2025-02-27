#include "header.h"

WiFiServer server(80);
// DNSServer dnsServer;

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);

    WiFi.mode(WIFI_AP_STA);

    if (!connectWifi("ELGUESABAL", "12345678") || !routerWifi("vampeta", "12345678")) {
    // if (!connectWifi("ELGUESABAL", "12345678")) {
    // if (!routerWifi("vampeta", "12345678")) {
        while (true) {

        }
    }

    // dnsServer.start(53, "*", "8.8.8.8");
    server.begin();



    // WiFiClient client;

    // if (client.connect("192.168.137.1", 3000)) {
    //     M5Cardputer.Display.println("Conectado ao servidor!");

    //     // Enviar requisição GET
    //     client.println("GET / HTTP/1.1");
    //     client.println("Host: 192.168.1.100:3000");
    //     client.println("Connection: close");
    //     client.println();  // Linha em branco obrigatória

    //     // Ler resposta do servidor
    //     M5Cardputer.Display.println("Resposta do servidor:");
    //     // while (client.available()) {
    //     //     String resposta = client.readStringUntil('\r');
    //     //     M5Cardputer.Display.println(resposta);
    //     // }

    //     // while (client.connected()) {
    //     //     M5Cardputer.Display.print(client.readString());
    //     // }

    //     // while (client.available()) {
    //     //     M5Cardputer.Display.printf("bytes a serem lidos: %d\n", client.available());
    //     // }

    //     // unsigned int time = 0;
    //     // do {
    //     //     M5Cardputer.Display.printf("bytes a serem lidos: %d\n", client.available());
    //     //     delay(100);
    //     //     time += 100;
    //     // } while (time < 3000);
    //     // M5Cardputer.Display.println(time < 3000 ? "leu com sucesso" : "a leitura falhou");

    //     client.stop();  // Fecha a conex
    // } else {
    //     M5Cardputer.Display.println("Falha ao conectar no servidor!");
    // }
}

std::set<WiFiClient *> clients;

void loop(void) {
    // dnsServer.processNextRequest();

    WiFiClient newClient = server.available();
    if (newClient) {
        clients.insert(new WiFiClient(newClient));
        M5Cardputer.Display.print("novo cliente -> ");
        M5Cardputer.Display.print(newClient.remoteIP());
        M5Cardputer.Display.print(":");
        M5Cardputer.Display.println(newClient.remotePort());
    }

    for (auto it = clients.begin(); it != clients.end(); ) {
        if (!(*it)->connected()) {
            M5Cardputer.Display.println("desconectou");
            (*it)->stop();
            delete *it;
            it = clients.erase(it);
        } else if ((*it)->available()) {
            String requestClient = (*it)->readString();
            // delay(1000);
            // M5Cardputer.Display.print(requestClient);
            // String res = request("192.168.137.1", 3000, requestClient);
            String res = request("192.168.4.2", 3000, requestClient);

            if (res) {
                (*it)->print(res);
            } else {
                // M5Cardputer.Display.println("deu erro no trem"); // NAO SEI OQ RESPONDER
            }
        } else {
            ++it;
        }
    }
}
#include "header.h"

WiFiServer server(80);

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);

    WiFi.mode(WIFI_AP_STA);

    if (!connectWifi("ELGUESABAL", "12345678") || !routerWifi("vampeta", "12345678")) {
        while (true) {

        }
    }

    server.begin();
}

void loop(void) {
    // WiFiClient client = server.available();
    // if (client) {
    //     M5Cardputer.Display.println("Cliente conectado!");
    //     while (client.connected()) {
    //         if (client.available()) {
    //             String request = client.readStringUntil('\r');
    //             M5Cardputer.Display.print("Recebido: ");
    //             M5Cardputer.Display.println(request);

    //             // Reencaminhar os dados para um servidor na internet
    //             WiFiClient forwardClient;
    //             if (forwardClient.connect("google.com", 80)) {
    //                 forwardClient.print(request);
    //                 M5Cardputer.Display.println("Dados encaminhados!");
    //             } else {
    //                 M5Cardputer.Display.println("Falha ao conectar ao servidor!");
    //             }
    //             forwardClient.stop();
    //         }
    //     }
    //     client.stop();
    //     M5Cardputer.Display.println("Cliente desconectado!");
    // }



    WiFiClient client = server.available();
    if (client) {
        M5Cardputer.Display.printf("conectado na porta: %d\n", client.remotePort());
        // client.println("aaaaaaaa\r\n");
        while (client.connected()) {
            if (client.available()) {
                // String request = client.readStringUntil('\r');
                // M5Cardputer.Display.println(request);

                // WiFiClient forwardClient;        // NAO ENTENDI NADA DO Q EU FIZ AKI
                // if (forwardClient.connect("google.com", 80)) {
                //     String res = forwardClient.readStringUntil('\r');
                //     M5Cardputer.Display.print(res);
                //     client.print(res);
                // }
            }
        }
    }
}
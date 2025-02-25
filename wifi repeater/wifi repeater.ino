#include "header.h"

WiFiServer server(80);

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);

    WiFi.mode(WIFI_AP_STA);

    // if (!connectWifi("ELGUESABAL", "12345678") || !routerWifi("vampeta", "12345678")) {
    if (!connectWifi("ELGUESABAL", "12345678")) {
        while (true) {

        }
    }

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



    // WiFiClient client = server.available();
    // if (client) {
    //     M5Cardputer.Display.printf("conectado na porta: %d\n", client.remotePort());
    //     // client.println("aaaaaaaa\r\n");
    //     while (client.connected()) {
    //         if (client.available()) {
    //             // String request = client.readStringUntil('\r');
    //             // M5Cardputer.Display.println(request);

    //             WiFiClient forwardClient;        // NAO ENTENDI NADA DO Q EU FIZ AKI
    //             if (forwardClient.connect("192.168.137.1", 3000)) {
    //                 // String res = forwardClient.readString();
    //                 // M5Cardputer.Display.print(res.c_str());
    //                 // client.print(res.c_str());
    //                 // M5Cardputer.Display.println("respondido");


    //                 client.println("GET / HTTP/1.1");
    //                 client.println("Host: 192.168.1.100:3000");
    //                 client.println("Connection: close");
    //                 client.println();  // Linha em branco obrigatória

    //                 int i = 0;
    //                 while (!forwardClient.available()) { // ESPERAR ATE TER BUFFER??
    //                     delay(10);
    //                     M5Cardputer.Display.printf("esperando: %d\n", i);
    //                     i++;
    //                 }

    //                 while (forwardClient.available()) {
    //                     M5Cardputer.Display.printf("teste: %s\n", forwardClient.readString().c_str());
    //                     client.print(forwardClient.readString());
    //                 }
    //             } else {
    //                 M5Cardputer.Display.println("nao foi respondido");
    //             }
    //             client.stop();
    //         }
    //     }
    // }


                                            // CONSEGUI REENCAMINHAR BYTES A OUTRO IP Q ESTA CONECTADO NO MESMO WIFI
    WiFiClient client = server.available();
    if (client) {
        M5Cardputer.Display.printf("cliente na porta: %d\n", client.remotePort());
        while (client.connected()) {
            if (client.available()) {
                WiFiClient forwardClient;
                // if (forwardClient.connect("192.168.137.1", 3000)) { // SERVIDOR CRIADO COM NODE.JS E COMPARTILHADO LOCALMENTE
                if (forwardClient.connect("google.com", 80)) {
                    forwardClient.print(client.readString());

                    while (!forwardClient.available()) {
                        delay(10);
                    }
                    while (forwardClient.available()) {
                        client.print(forwardClient.readString());
                    }
                    forwardClient.stop();
                } else {
                    M5Cardputer.Display.println("nao foi respondido");
                }
            }
        }
        M5Cardputer.Display.print("desconectou");
        client.stop();
    }
                                            // CONSEGUI REENCAMINHAR BYTES A OUTRO IP Q ESTA CONECTADO NO MESMO WIFI
}
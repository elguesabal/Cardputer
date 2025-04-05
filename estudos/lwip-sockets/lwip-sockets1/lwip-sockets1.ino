#include <M5Cardputer.h>
#include <WiFi.h>
#include <lwip/sockets.h>

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
    WiFi.softAP("vampeta");


    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock < 0) {
        M5Cardputer.Display.println("erro ao criar socket");
        return ;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(80);

    bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)); // TENHO Q VERIFICAR???

    listen(serverSock, 5);
    M5Cardputer.Display.println("rodando na porta 80");

    while (true) {
        struct sockaddr_in clientAddr;
        socklen_t addrLen = sizeof(clientAddr);
        int clientSock = accept(serverSock, (struct sockaddr *)&clientAddr, &addrLen);

        if (clientSock >= 0) {
            M5Cardputer.Display.println("cliente conectado");
            char message[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nOlá do ESP32!";
            send(clientSock, message, sizeof(message), 0);
            close(clientSock);
        }
    }
}

void loop(void) {

}
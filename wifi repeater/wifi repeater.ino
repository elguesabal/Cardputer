#include "header.h"

std::vector<pollfd> fds;
Dns *dns;
Http *http;

void setup(void) {
    cardputerStart();
    wifiStart();
    acessPointerStart();
    dns = new Dns(DNS_PORT, fds);
    http = new Http(HTTP_PORT, fds);
}

void loop(void) {
    int ret = poll(fds.data(), fds.size(), -1);

    // if (ret < 0) {
    //     M5CARDPUTER.println("ret < 0");
    //     return ;
    // }
    // if (fds[0].revents & POLLIN) {
    //     sockaddr_in client_addr{};
    //     socklen_t client_len = sizeof(client_addr);
    //     int client_fd = accept(fds[0].fd, (sockaddr *)&client_addr, &client_len);

    //     if (client_fd >= 0) {
    //         M5CARDPUTER.println("cliente conectado");

    //         // char buffer[512];
    //         // memset(buffer, 0, sizeof(buffer));
    //         // int len = recv(client_fd, buffer, sizeof(buffer) - 1, 0);

    //         // if (len > 0) {
    //         //     M5CARDPUTER.printf("Recebido (%d bytes): \n%s\n", len, buffer);
    //         // }
    //     }
    // } else {
    //     M5CARDPUTER.println("???");
    // }



    if (ret < 0) {
        M5CARDPUTER.println("ret < 0");
        return ;
    }
    if (fds[0].revents & POLLIN) {
        dns->requestDns();

        static int n_dns = 0;
        n_dns++;
        M5CARDPUTER.printf("requisicao dns: %d\n", n_dns);
    }
    if (fds[1].revents & POLLIN) {
        // http->requestHttp();

        static int n_http = 0;
        n_http++;
        M5CARDPUTER.printf("requisicao http: %d\n", n_http);
    }
}
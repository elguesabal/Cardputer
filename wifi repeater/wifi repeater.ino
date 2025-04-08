#include "header.h"

std::vector<pollfd> fds;
Dns *dns;

void setup(void) {
    cardputerStart();
    wifiStart();
    acessPointerStart();
    dns = new Dns(DNS_PORT, fds);
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
    }
}
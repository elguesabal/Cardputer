#include "header.h"

std::vector<pollfd> fds;

void setup(void) {
    cardputerStart();
    wifiStart();
    acessPointerStart();
    Dns dns(DNS_PORT, fds);
}

void loop(void) {
    int ret = poll(fds.data(), fds.size(), -1);

    if (ret > 0) {
        if (fds[0].revents & POLLIN) {
            M5CARDPUTER.println("DNS");
        }
    } else {
        M5CARDPUTER.println("???");
    }
}
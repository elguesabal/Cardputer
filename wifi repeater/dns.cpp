#include "header.h"

Dns::Dns(int port) {
    this->pfd.fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (this->pfd.fd < 0) {
        M5CARDPUTER.println("Erro ao criar socket DNS");
        while (true) {
            delay(1000);
        }
    }
    memset(&this->dns, 0, sizeof(this->dns));
    this->dns.sin_family = AF_INET;
    this->dns.sin_port = htons(port);
    this->dns.sin_addr.s_addr = INADDR_ANY;
    if (bind(this->pfd.fd, (struct sockaddr *)&this->dns, sizeof(this->dns)) < 0) {
        M5CARDPUTER.println("Erro ao associar o socket ao endereço e porta");
        close(this->pfd.fd);
        while (true) {
            delay(1000);
        }
    }
    M5CARDPUTER.println("Servidor DNS iniciado");
}

Dns::~Dns(void) {

}
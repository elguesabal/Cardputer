#include "header.h"

Dns::Dns(int port, std::vector<pollfd> &fds) {
    this->setPfd();
    this->setDns(port);
    this->setBind();
    this->setListen();

    fds.push_back(this->_pfd);

    #if defined(M5CARDPUTER)
        M5CARDPUTER.println("Servidor DNS iniciado");
    #endif
}

Dns::~Dns(void) {

}

void Dns::setPfd(void) {
    this->_pfd.fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (this->_pfd.fd < 0) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Erro ao criar socket DNS");
        #endif
        while (true) {
            delay(1000);
        }
    }
    this->_pfd.events = POLLIN;
}

void Dns::setDns(int port) {
    memset(&this->_dns, 0, sizeof(this->_dns));
    this->_dns.sin_family = AF_INET;
    this->_dns.sin_port = htons(port);
    this->_dns.sin_addr.s_addr = INADDR_ANY;
}

void Dns::setBind(void) {
    if (bind(this->_pfd.fd, (struct sockaddr *)&this->_dns, sizeof(this->_dns)) < 0) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Erro ao associar o socket ao endereço e porta");
        #endif
        close(this->_pfd.fd);
        while (true) {
            delay(1000);
        }
    }
}

void Dns::setListen(void) {
    if (listen(this->_pfd.fd, 5) < 0) { // PQ RAIOS TA DANDO ERRO???
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Erro no listen()");
        #endif
        while (true) {
            delay(1000);
        }
    }
}
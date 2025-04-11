#include "https.hpp"

Https::Https(int port, std::vector<pollfd> &fds, M5GFX *M5CARDPUTER) {
    this->setPfd();
    this->setHttps(port);
    this->setBind();
    this->setListen();

    fds.push_back(this->_pfd);

    this->_display = M5CARDPUTER;
    this->_display->println("Servidor HTTPS iniciado");
}

Https::Https(int port, std::vector<pollfd> &fds) {
    this->setPfd();
    this->setHttps(port);
    this->setBind();
    this->setListen();

    fds.push_back(this->_pfd);

    this->_display = nullptr;
}

Https::~Https(void) {
    close(this->_pfd.fd);
}

void Https::setPfd(void) {
    this->_pfd.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->_pfd.fd < 0) {
        if (this->_display) {
            this->_display->println("Erro ao criar socket HTTPS");
        }
        while (true) {
            delay(1000);
        }
    }
    this->_pfd.events = POLLIN;
}

void Https::setHttps(int port) {
    this->_https.sin_family = AF_INET;
    this->_https.sin_port = htons(port);
    this->_https.sin_addr.s_addr = htonl(INADDR_ANY);
}

void Https::setBind(void) {
    if (bind(this->_pfd.fd, (struct sockaddr *)&this->_https, sizeof(this->_https)) < 0) {
        if (this->_display) {
            this->_display->println("Erro ao associar o socket ao endereço e porta");
        }
        close(this->_pfd.fd);
        while (true) {
            delay(1000);
        }
    }
}

void Https::setListen(void) {
    if (listen(this->_pfd.fd, 5) < 0) {
        if (this->_display) {
            this->_display->println("Erro no listen()");
        }
        while (true) {
            delay(1000);
        }
    }
}
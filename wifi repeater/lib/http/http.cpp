#include "http.hpp"

Http::Http(int port, std::vector<pollfd> &fds, M5GFX *M5CARDPUTER) {
    this->setPfd();
    this->setHttp(port);
    this->setBind();
    this->setListen();

    fds.push_back(this->_pfd);

    this->_display = M5CARDPUTER;
    this->_display->println("Servidor HTTP iniciado");
}

Http::Http(int port, std::vector<pollfd> &fds) {
    this->setPfd();
    this->setHttp(port);
    this->setBind();
    this->setListen();

    fds.push_back(this->_pfd);

    this->_display = nullptr;
}

Http::~Http(void) {
    close(this->_pfd.fd);
}

void Http::setPfd(void) {
    this->_pfd.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->_pfd.fd < 0) {
        if (this->_display) {
            this->_display->println("Erro ao criar socket HTTP");
        }
        while (true) {
            delay(1000);
        }
    }
    this->_pfd.events = POLLIN;
}

void Http::setHttp(int port) {
    this->_http.sin_family = AF_INET;
    this->_http.sin_port = htons(port);
    this->_http.sin_addr.s_addr = htonl(INADDR_ANY);
}

void Http::setBind(void) {
    if (bind(this->_pfd.fd, (struct sockaddr *)&this->_http, sizeof(this->_http)) < 0) {
        if (this->_display) {
            this->_display->println("Erro ao associar o socket ao endereço e porta");
        }
        close(this->_pfd.fd);
        while (true) {
            delay(1000);
        }
    }
}

void Http::setListen(void) {
    if (listen(this->_pfd.fd, 5) < 0) {
        if (this->_display) {
            this->_display->println("Erro no listen()");
        }
        while (true) {
            delay(1000);
        }
    }
}
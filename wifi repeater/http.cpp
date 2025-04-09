#include "header.h"

Http::Http(int port, std::vector<pollfd> &fds) {
    this->setPfd();
    this->setHttp(port);
    this->setBind();
    this->setListen();

    fds.push_back(this->_pfd);

    #if defined(M5CARDPUTER)
        M5CARDPUTER.println("Servidor HTTP iniciado");
    #endif
}

Http::~Http(void) {

}

void Http::setPfd(void) {
    this->_pfd.fd = socket(AF_INET, SOCK_STREAM, 0);
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

void Http::setHttp(int port) {
    this->_http.sin_family = AF_INET;
    this->_http.sin_port = htons(port);
    this->_http.sin_addr.s_addr = htonl(INADDR_ANY);
}

void Http::setBind(void) {
    if (bind(this->_pfd.fd, (struct sockaddr *)&this->_http, sizeof(this->_http)) < 0) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("Erro ao associar o socket ao endereço e porta");
        #endif
        close(this->_pfd.fd);
        while (true) {
            delay(1000);
        }
    }
}

void Http::setListen(void) {
    if (listen(this->_pfd.fd, 5) < 0) {
        #if defined(M5CARDPUTER)
            Serial.println("Erro no listen()");
        #endif
        while (true) {
            delay(1000);
        }
    }
}
#include "header.h"

Dns::Dns(int port, std::vector<pollfd> &fds) {
    this->setPfd();
    this->setDns(port);
    this->setBind();

    fds.push_back(this->_pfd);

    #if defined(M5CARDPUTER)
        M5CARDPUTER.println("Servidor DNS iniciado");
    #endif
}

Dns::~Dns(void) {

}

void Dns::setPfd(void) {
    this->_pfd.fd = socket(AF_INET, SOCK_DGRAM, 0);
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
    // memset(&this->_dns, 0, sizeof(this->_dns));
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

void Dns::requestDns(void) {
    char buffer[512];
    sockaddr_in client_addr{};

    memset(buffer, 0, 512);
    socklen_t client_len = sizeof(client_addr);
    ssize_t bytes_received = recvfrom(this->_pfd.fd, buffer, 512, 0, (sockaddr *)&client_addr, &client_len);

    if (bytes_received < 0) {
        M5CARDPUTER.println("Erro no recvfrom()");
        close(this->_pfd.fd);
        return ;
    }

    // // std::cout << "Recebido " << bytes_received << " bytes de " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << "\n";
    // M5CARDPUTER.printf("Recebido %d bytes de %s:%d\n", bytes_received, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // // Vamos só imprimir os primeiros bytes do pacote DNS
    // for (int i = 0; i < bytes_received; i++) {
    //     M5CARDPUTER.printf("%02x ", (unsigned char)buffer[i]);
    //     if ((i + 1) % 16 == 0) M5CARDPUTER.println("");
    // }
    // M5CARDPUTER.println("");

    // M5CARDPUTER.println("mensagem udp recebida");



    // std::string domain;
    // int i = 12;
    // while (buffer[i] != 0) {
    //     int len = buffer[i];
    //     for (int j = 0; j < len; ++j) {
    //         domain += buffer[i + j + 1];
    //     }
    //     domain += '.';
    //     i += len + 1;
    // }
    // // remove o ponto final
    // if (!domain.empty() && domain.back() == '.') domain.pop_back();

    // M5CARDPUTER.println(domain.c_str());



    // // Salva ID da requisição
    // uint16_t id = (buffer[0] << 8) | buffer[1];

    // // Constrói resposta
    // uint8_t response[512];
    // memset(response, 0, sizeof(response));

    // memcpy(response, buffer, bytes_received); // copia query original
    // response[2] = 0x81; // flags: QR = 1, opcode = 0, AA = 1
    // response[3] = 0x80; // flags: RA = 1
    // response[7] = 0x01; // ANCOUNT = 1 (resposta única)

    // int query_end = 12;
    // while (buffer[query_end] != 0 && query_end < bytes_received) query_end++; // final da query
    // query_end += 5; // pula \0, tipo (2B), classe (2B)

    // // Resposta começa após query
    // int pos = query_end;

    // // Nome (pointer para o início da query: 0xC00C)
    // response[pos++] = 0xC0;
    // response[pos++] = 0x0C;

    // // Tipo A
    // response[pos++] = 0x00;
    // response[pos++] = 0x01;

    // // Classe IN
    // response[pos++] = 0x00;
    // response[pos++] = 0x01;

    // // TTL
    // response[pos++] = 0x00;
    // response[pos++] = 0x00;
    // response[pos++] = 0x00;
    // response[pos++] = 0x3C; // 60 segundos

    // // Tamanho dos dados
    // response[pos++] = 0x00;
    // response[pos++] = 0x04; // 4 bytes (IPv4)

    // // IP de resposta (192.168.4.1)
    // IPAddress ip = WiFi.softAPIP();
    // response[pos++] = ip[0];
    // response[pos++] = ip[1];
    // response[pos++] = ip[2];
    // response[pos++] = ip[3];

    // // Envia resposta
    // sendto(this->_pfd.fd, response, pos, 0, (sockaddr*)&client_addr, client_len);



    // Cria socket UDP para contato com DNS real (se ainda não tiver)
    int upstream_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    sockaddr_in google_dns{};
    google_dns.sin_family = AF_INET;
    google_dns.sin_port = htons(53);
    inet_aton("8.8.8.8", &google_dns.sin_addr);

    // Envia a query original para o DNS público
    sendto(upstream_sock, buffer, bytes_received, 0, (sockaddr*)&google_dns, sizeof(google_dns));

    // Espera resposta
    uint8_t response[512];
    sockaddr_in from;
    socklen_t from_len = sizeof(from);
    int res_len = recvfrom(upstream_sock, response, sizeof(response), 0, (sockaddr*)&from, &from_len);

    // Repassa para o cliente original
    sendto(this->_pfd.fd, response, res_len, 0, (sockaddr*)&client_addr, client_len);

    close(upstream_sock); // ou mantenha aberto se for reutilizar

    static int n = 0;
    M5CARDPUTER.println(n++);
}
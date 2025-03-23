#include "header.h"

/// @brief INICIA O WEBSERVER
void serverStart(void) {
    server.onNotFound(request);
    server.begin();
    #if defined(M5CARDPUTER)
        M5CARDPUTER.println("Server iniciado");
    #endif
}

/// @brief REENCAMINHA A REQUISICAO PARA O ENDERECO CERTO
void request(void) {
    String url = getUrl();

    server.send(200, "text/plain", url);
}

/// @brief REMONTA A URL Q FOI USADA PARA FAZER UMA REQUISICAO
/// @return RETORNA A URL COMPLETA
String getUrl(void) {
    String url = server.hostHeader() + server.uri() + (server.args() ? "?" : "");

    for (unsigned int i = 0; i < server.args(); i++) {
        url += (i ? "&" : "") + server.argName(i) + "=" + server.arg(i);
    }
    return (url);
}











// void request(void) {
//     String url = getUrl();

//     if (client.connect("192.168.4.2", 3000)) {
//         // Envia uma requisição HTTP GET
//         client.println("GET / HTTP/1.1");
//         client.println("Host: example.com");
//         client.println("Connection: close");
//         client.println(); // Linha em branco para indicar fim do cabeçalho
//     } else {
//         M5CARDPUTER.println("Falha ao conectar ao servidor.");
//     }

//     delay(1000);
//     String res;
//     while (client.available()) {
//         res += client.readStringUntil('\n');
//     }
//     M5CARDPUTER.print(res);
//     client.stop();

//     // server.send(200, "text/plain", url);
//     server.send(200, "text/plain", res);
//     // server.send(200, "text/plain", "res");
// }

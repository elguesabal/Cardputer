#include "header.h"

/// @brief INICIA O WEBSERVER
void serverStart(void) {
    server.onNotFound(request);
    server.begin();
    #if defined(M5CARDPUTER)
        M5CARDPUTER.println("Server iniciado");
    #endif
}

void request(void) {
    String url = server.hostHeader() + server.uri() + (server.args() ? "?" : "");

    for (unsigned int i = 0; i < server.args(); i++) {
        url += server.argName(i) + "=" + server.arg(i);
    }
    server.send(200, "text/plain", url);
}
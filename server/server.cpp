#include "header.h"

void webServerStart(void) {
    webServer.on("/", home);

    webServer.onNotFound([]() {
        M5Cardputer.Display.println("rota nao encontrada");
        webServer.send(200, "text/html", "rota nao encontrada");
    });

    webServer.begin();
}

void home(void) {
    String html = getPage("/Pages/index.html"); // VERIFICAR PQ ESSA FUNCAO ESTA SEMPRE RETORNANDO VAZIA
    M5Cardputer.Display.printf("teste: '%s'\n", html.c_str());
    webServer.send(200, "text/html", html);
}

// void getRoute(void) {

// }
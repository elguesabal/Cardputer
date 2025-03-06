#include "header.h"

/// @brief INICIA O BACK END E DEFINE AS ROTAS
void backEndStart(void) {
    backEnd->on("/", []() {
        backEnd->send(200, "text/html", "<p>Pagina home</p>");
    });
    backEnd->onNotFound([]() {
        backEnd->send(404, "text/html", "<p>Erro: Pagina nao existe</p>");
    });
    backEnd->begin();
}
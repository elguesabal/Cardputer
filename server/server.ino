#include "header.h"

WebServer webServer(80);

void setup(void) {
    cardputerStart();
    sdStart();
    acessPointerStart();
    webServerStart();
}

void loop(void) {
    webServer.handleClient();
}
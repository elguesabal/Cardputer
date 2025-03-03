#include "header.h"

WebServer webServer(80);

void setup(void) {
    cardputerStart();
    acessPointerStart();
    webServerStart();
}

void loop(void) {
    webServer.handleClient();
}
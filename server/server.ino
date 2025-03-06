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
    // delay(2);//allow the cpu to switch to other tasks // ISSO E NECESSARIO??
}
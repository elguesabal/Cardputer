#include "header.h"

// WebServer frontEnd(80);
// WebServer backEnd(4242);

WebServer *frontEnd = nullptr;
WebServer *backEnd = nullptr;

void setup(void) {
    cardputerStart();
    sdStart();
    acessPointerStart();
    frontEndStart();
    backEndStart();
}

void loop(void) {
    frontEnd->handleClient();
    backEnd->handleClient();
    delay(2);
}
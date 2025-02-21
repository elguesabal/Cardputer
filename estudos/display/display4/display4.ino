#include <M5Cardputer.h>

void setup(void) {
    M5Cardputer.begin();
}

void loop(void) {
    M5Cardputer.Display.println("M5Cardputer está rodando...");
    delay(1000);
}
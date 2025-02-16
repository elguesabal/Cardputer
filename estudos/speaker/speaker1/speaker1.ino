#include <M5Cardputer.h>

void setup(void) {
    M5Cardputer.begin(M5.config());
}

void loop(void) {
    M5Cardputer.Speaker.tone(1000, 500);
    delay(1000);
}
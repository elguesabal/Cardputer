#include "teste.h"

void teste(void) {
    static unsigned int i = 1;
    if (i < 6) {
        char n = 48 + i;
        M5.Display.println(n);
        i++;
        delay(1000);
    }
}
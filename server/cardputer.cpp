#include "header.h"

void cardputerStart(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
}
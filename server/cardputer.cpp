#include "header.h"

/// @brief INICIA E CONFIGURA O DISPLAY DO CARDPUTER
void cardputerStart(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
}
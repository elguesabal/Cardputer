#include "header.h"

/// @brief INICIA E CONFIGURA O DISPLAY DO CARDPUTER
void cardputerStart(void) {
    #if !defined(M5CARDPUTER)
        return ;
    #endif
    M5Cardputer.begin();
    M5CARDPUTER.setTextScroll(true);
    M5CARDPUTER.setTextColor(GREEN);
    M5CARDPUTER.setTextSize(1);
}
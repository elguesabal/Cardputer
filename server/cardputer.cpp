#include "header.h"

/// @brief INICIA E CONFIGURA O DISPLAY DO CARDPUTER
void cardputerStart(void) {
    // PROXIMA IDEIA DE INICIAR SEM DISPLAY
    // if (M5Cardputer.BtnA.pressedFor(1000)) {
        // Botao A foi segurado por 1 segundo
    // }

    #if defined(M5CARDPUTER)
        M5Cardputer.begin();
        M5CARDPUTER.setTextScroll(true);
        M5CARDPUTER.setTextColor(GREEN);
        M5CARDPUTER.setTextSize(1);
    #endif
}
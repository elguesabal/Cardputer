#include "header.h"

/// @brief INICIA O CARTAO SD E CASO O CARTAO NAO ESTEJA PRESENTE ESPERA ATE UM CARTAO SER INSERIDO
void sdStart(void) {
    SPI.begin(SCK, MISO, MOSI, CS);
    if (!SD.begin(CS, SPI, 25000000)) {
        M5Cardputer.Display.println("Aguardando insercao do carta SD...");
        while (!SD.begin(CS, SPI, 25000000)) {
            delay(1000);
        }
        M5Cardputer.Display.println("Cartao SD inserido");
    }
}
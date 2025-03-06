#include "header.h"

/// @brief INICIA O CARTAO SD
void sdStart(void) {
    SPI.begin(SCK, MISO, MOSI, CS);
    if (!SD.begin(CS, SPI, 25000000)) {
        #if defined(M5CARDPUTER)
            M5CARDPUTER.println("sd nao disponivel");
        #endif
        while (true) {

        }
    }
}

/// @brief BUSCA UM ARQUIVO NO CARTAO SD E RETORNA O FILEDESCRIPTION
/// @param path CAMINHO DO ARQUIVO COMPLETO (APARTIR DO "/Pages" Q DEVE SER INCLUSO NO path)
/// @return RETONAR UMA OBJETO File Q CONTEM O FD (O USUARIO DEVE VERIFICAR SE O ARQUIVO FOI ABERTO)
File getFile(String path) {
    return (SD.open(path.c_str()));
}
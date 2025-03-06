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

/// @brief VERIFICA SE EXISTE UMA PASTA OU ARQUIVO
/// @param path CAMINHO COMPLETO A SRE VERIFICADO
bool checkPath(const char *path) {
    return (SD.exists(path));
}

/// @brief BUSCA UM ARQUIVO NO CARTAO SD E RETORNA O FILEDESCRIPTION
/// @param path CAMINHO DO ARQUIVO COMPLETO
/// @return RETONAR UMA OBJETO File QUE CONTEM O FD (O USUARIO DEVE VERIFICAR SE O ARQUIVO FOI ABERTO)
File getFile(String path) {
    return (SD.open(path.c_str()));
}
#include "header.h"

/// @brief INICIA O CARTAO SD
void sdStart(void) {
    SPI.begin(SCK, MISO, MOSI, CS);

    if (!SD.begin(CS, SPI, 25000000)) {
        M5Cardputer.Display.println("sd nao disponivel");
        while (true) {

        }
    }
}

/// @brief BUSCA UM ARQUIVO NO CARTAO SD E RETORNA O CONTEUDO DO ARQUIVO
/// @param path CAMINHO DO ARQUIVO COMPLETO (APARTIR DO "/Pages" Q NAO DEVE SER INCLUSO NO path)
/// @return RETONAR O CONTEUDO DO ARQUIVO E CASO OCORRA ALGUM ERRO RETORNA UMA STRING VAZIA
String getPage(String path) {
    File file = SD.open(path);

    if (!file) {
        return ("");
    }
    String html = file.readString();
    file.close();
    return (html);
}
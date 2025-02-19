#include <M5Cardputer.h>
#include <SPI.h>
#include <SD.h>

#define SCK 40
#define MISO 39
#define MOSI 14
#define CS 12

void setup(void) {
    M5Cardputer.begin(M5.config());
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(1);
    M5Cardputer.Display.setTextDatum(middle_center);

    // INICIA O CARTAO SD
    SPI.begin(SCK, MISO, MOSI, CS);
    if (!SD.begin(CS, SPI, 25000000)) {
        M5Cardputer.Display.drawString("sem cartao de memoria", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
        return ;
    }
    // INICIA O CARTAO SD

    M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2, BLACK);

    // ABRE O ARQUIVO NO MODO ESCRITA E ESCREVE
    File file = SD.open("/42.txt", FILE_WRITE);
    if (!file) {
        M5Cardputer.Display.drawString("erro ao abrir arquivo", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
        return ;
    }

    if (file.print("vampeta 42")) {
        M5Cardputer.Display.drawString("escreveu no cartao", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    } else {
        M5Cardputer.Display.drawString("nao escreveu nada", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    }
    // ABRE O ARQUIVO NO MODO ESCRITA E ESCREVE

    // FECHA O ARQUIVO
    file.close();
    // FECHA O ARQUIVO
}

void loop(void) {

}
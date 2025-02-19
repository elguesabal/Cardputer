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

    // ABRE O ARQUIVO NO MODO LEITURA E LE O ARQUIVO
    File file = SD.open("/42.txt");
    if (!file) {
        M5Cardputer.Display.drawString("erro ao abrir arquivo", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
        return ;
    }
    int x = 5, y = 10;
    while (file.available()) {
        std::string line;
        line.push_back(file.read());
        if (line == "\n") {
            y += 10;
            x = 5;
        } else {
            M5Cardputer.Display.drawString(line.c_str(), x, y);
            x += 5;
        }
    }
    // ABRE O ARQUIVO NO MODO LEITURA E LE O ARQUIVO

    // FECHA O ARQUIVO
    file.close();
    // FECHA O ARQUIVO
}

void loop(void) {

}
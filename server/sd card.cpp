#include "header.h"

void sdStart(void) {
    SPI.begin(SCK, MISO, MOSI, CS);

    if (!SD.begin(CS, SPI, 25000000)) {
        M5Cardputer.Display.println("sd nao disponivel");
        while (true) {

        }
    }
}

String getPage(const char *path) {
    File file = SD.open(path);

    if (!file) {
        return ("");
    }
    String html = file.readString();
    file.close();
    return (html);
}
#include <M5Cardputer.h>

void setup(void) {
    M5Cardputer.begin(M5.config());
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(5);
    M5Cardputer.Display.setTextDatum(middle_center);
}

void loop(void) {
    std::string key;

    M5Cardputer.update();
    if (!M5Cardputer.Keyboard.isPressed()) {
        M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), BLACK);
    }
    if (M5Cardputer.Keyboard.isChange()) {
        M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), BLACK);

        // for (unsigned int i = 0; i < M5Cardputer.Keyboard.keysState().word.size(); i++) {
        //     key += M5Cardputer.Keyboard.keysState().word[i];
        // }
        for (auto c : M5Cardputer.Keyboard.keysState().word) { // FORMA AUTERNATIVA DE PERCORRER UM ARRAY INTRODUZIDA NA VERSAO c++11
            key += c;
        }

        M5Cardputer.Display.drawString(key.c_str(), M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    }
    delay(100);
}
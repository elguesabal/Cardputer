#include <M5Cardputer.h>

bool sound = false;
uint8_t volume = 0;

void updateDisplay(void) {
    char n[10];
    std::string volume1 = "volume: ";
    std::string volume2 = "getVolume: ";

    itoa(volume, n, 10);
    volume1 += n;
    itoa(M5Cardputer.Speaker.getVolume(), n, 10);
    volume2 += n;

    M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), BLACK);
    M5Cardputer.Display.drawString(volume1.c_str(), 0, 20);
    M5Cardputer.Display.drawString(volume2.c_str(), 0, 40);
    M5Cardputer.Display.drawString((sound ? "player" : "stop"), 0, M5Cardputer.Display.height() - 20);
}

void setup(void) {
    M5Cardputer.begin(M5.config());
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(2);
    M5Cardputer.Speaker.setVolume(volume);
    updateDisplay();
}

void loop(void) {
    M5Cardputer.update();

    if (M5Cardputer.BtnA.wasPressed()) {
        if (sound) {
            M5Cardputer.Speaker.end();
            sound = false;
        } else {
            M5Cardputer.Speaker.tone(1000, 100000000);
            sound = true;
        }
        updateDisplay();
    }

    if (M5Cardputer.Keyboard.isChange() || M5Cardputer.Keyboard.isPressed()) {
        if (M5Cardputer.Keyboard.keysState().word[0] == ';') {
            volume += 1;
            M5Cardputer.Speaker.setVolume(volume);
            updateDisplay();
        } else if (M5Cardputer.Keyboard.keysState().word[0] == '.') {
            volume -= 1;
            M5Cardputer.Speaker.setVolume(volume);
            updateDisplay();
        }
    }

    delay(100);
}
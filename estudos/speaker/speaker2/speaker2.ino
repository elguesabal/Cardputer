#include <M5Cardputer.h>

void setup(void) {
    M5Cardputer.begin(M5.config());
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(4);
    M5Cardputer.Display.setTextDatum(middle_center);
}

void loop(void) {
    M5Cardputer.update();
    
    if (M5Cardputer.Keyboard.isChange() || M5Cardputer.Keyboard.isPressed()) {
        M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), BLACK);

        if (M5Cardputer.Keyboard.keysState().word[0] == ';') {
            M5Cardputer.Display.drawString("player", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
            M5Cardputer.Speaker.tone(1000, 100000);
        } else if (M5Cardputer.Keyboard.keysState().word[0] == '.') {
            M5Cardputer.Display.drawString("stop", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
            M5Cardputer.Speaker.end();
        }
    }
    delay(200);
}
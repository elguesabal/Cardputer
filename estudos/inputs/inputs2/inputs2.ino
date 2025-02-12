#include <M5Cardputer.h>
#include <string>

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(2);
    M5Cardputer.Display.setTextDatum(middle_center);
}

unsigned int width = M5Cardputer.Display.width();
unsigned int height = M5Cardputer.Display.height();
std::string key;

void loop(void) {
    M5Cardputer.Display.clear();

    if (M5Cardputer.Keyboard.available()) {
        key = M5Cardputer.Keyboard.read();

        M5Cardputer.Display.fillRect(0, 0, width, height, BLACK);
        M5Cardputer.Display.drawString(key.c_str(), width / 2, height / 2);
    }

    delay(1000);
}
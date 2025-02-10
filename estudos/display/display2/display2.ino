#include <M5Cardputer.h>
#include <stdlib.h>

void setup(void) {
    M5Cardputer.begin(M5.config());

    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(5);
    M5Cardputer.Display.setTextDatum(middle_center);
    M5Cardputer.Display.drawRect(40, 25, 160, 85, GREEN);
}

void loop(void) {
    static unsigned int i = 1;
    char n[5];

    itoa(i, n, 10);
    M5Cardputer.Display.fillRect(45, 30, 150, 75, BLACK);
    M5Cardputer.Display.drawString(n, M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    i++;
    delay(1000);
}
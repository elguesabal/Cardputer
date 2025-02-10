#include <M5Cardputer.h>

void setup(void) {
    M5Cardputer.begin(M5.config());
}

void loop(void) {
    static int x = 0;
    static bool direction = true;

    M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), BLACK);
    M5Cardputer.Display.fillCircle(x, 72, 10, GREEN);
    x += (direction ? 10 : -10);

    if (x == M5Cardputer.Display.width()) {
        direction = false;
    } else if (x == 0) {
        direction == true;
    }

    char width[10];
    itoa(M5Cardputer.Display.width(), width, 10);
    M5.Display.println(width);

    delay(500);
}
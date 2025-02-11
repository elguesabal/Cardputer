#include <M5Cardputer.h>

void clearBackgrownd(void) {
    M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), BLACK);
}

void circle(int &x) {
    M5Cardputer.Display.fillCircle(x, 72, 10, GREEN);
}

void shadow(int &x, bool direction, int amount) {
    for (unsigned int i = 1; i - 1 < amount; ++i) {
        M5Cardputer.Display.drawCircle(x + i * (direction ? -20 : 20), 72, 10, GREEN);
    }
}

void redirection(int *x, bool *direction) {
    if (*x == M5Cardputer.Display.width()) {
        *direction = false;
    } else if (*x == 0) {
        *direction = true;
    }
    *x += (*direction ? 10 : -10);
}

void setup(void) {
    M5Cardputer.begin(M5.config());
}

void loop(void) {
    static int x = 0;
    static bool direction = true;

    clearBackgrownd();
    circle(x);
    shadow(x, direction, 3);
    redirection(&x, &direction);

    delay(100);
}
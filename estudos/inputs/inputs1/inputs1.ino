#include <M5Cardputer.h>

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(1);
    M5Cardputer.Display.setTextDatum(middle_center);
}

void loop(void) {
    M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), BLACK);
    M5Cardputer.update();

    if (M5Cardputer.BtnA.wasPressed()) {
        M5Cardputer.Display.drawString("Botao A foi pressionado!", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    }

    if (M5Cardputer.BtnA.isPressed()) {
        M5Cardputer.Display.drawString("Botao A esta sendo segurado!", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    }

    if (M5Cardputer.BtnA.wasReleased()) {
        M5Cardputer.Display.drawString("Botao A foi solto!", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    }

    if (M5Cardputer.BtnA.pressedFor(5000)) {
        M5Cardputer.Display.drawString("Botao A foi segurado por 1 segundo!", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    }

    delay(500);
}
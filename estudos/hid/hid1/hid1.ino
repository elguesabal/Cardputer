#include <M5Cardputer.h>
#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

void setup() {
    M5.begin();        // Inicializa o M5Cardputer
    Serial.begin(115200); // Inicializa a comunicação serial

    Keyboard.begin();  // Inicializa o teclado USB
    USB.begin();       // Inicializa o modo USB
}

void loop() {
    M5.update();

    // Se houver entrada na Serial, envia o próximo caractere na tabela ASCII
    if (Serial.available() > 0) {
        char inChar = Serial.read();
        Keyboard.write(inChar + 1); // Envia a próxima letra na tabela ASCII
    }

    // Botões do Cardputer para testes
    if (M5.BtnA.wasPressed()) {
        Keyboard.print("Hello, World!");  // Envia "Hello, World!"
    }

    if (M5.BtnB.wasPressed()) {
        Keyboard.write(KEY_RETURN); // Simula "Enter"
    }
}
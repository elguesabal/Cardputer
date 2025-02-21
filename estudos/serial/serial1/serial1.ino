#include "M5Cardputer.h"

void setup() {
    M5Cardputer.begin();
    Serial.begin(115200);  
    Serial.println("Digite algo no monitor serial:");
}

void loop() {
    if (Serial.available()) {
        String received = Serial.readString();
        Serial.print("Você digitou: ");
        Serial.println(received);
    }
}

#include <M5Cardputer.h>
#include <WiFi.h>

void setup(void) {
    M5Cardputer.begin();

    M5Cardputer.Display.println("conectando ao wifi");
    WiFi.begin("ELGUESABAL", "12345678");

    while (WiFi.status() != WL_CONNECTED) {
        M5Cardputer.Display.println("conectando");
        delay(1000);
    }

    M5Cardputer.Display.println("wifi conectado");
    M5Cardputer.Display.print("endereco ip: ");
    M5Cardputer.Display.println(WiFi.localIP());
}

void loop(void) {

}
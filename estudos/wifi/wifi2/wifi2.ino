#include <M5Cardputer.h>
#include <WiFi.h>

void setup(void) {
    M5Cardputer.begin();

    WiFi.softAP("vampeta", "12345678");

    M5Cardputer.Display.println("Ponto de acesso criado!");
    M5Cardputer.Display.print("Endereço IP: ");
    M5Cardputer.Display.println(WiFi.softAPIP());
}

void loop(void) {

}
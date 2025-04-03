#include <M5Cardputer.h>
#include <WiFi.h>
#include <lwip/sockets.h>

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
    WiFi.softAP("vampeta");
}

void loop(void) {

}
#include <M5Cardputer.h>
#include "WiFiCustom.h"

void setup(void) {
    M5Cardputer.begin();

    WiFi.softAP("vampeta");
}

void loop(void) {

}
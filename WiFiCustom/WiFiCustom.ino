#include <M5Cardputer.h>
#include "WiFiCustom.h"

void setup(void) {
    M5Cardputer.begin();

    if (!WiFi.softAP("vampeta")) {
        M5Cardputer.Display.println("Erro");
        return ;
    }

    WiFi.softAPsetHostname("MeuCardputer");
    // M5Cardputer.Display.println(WiFi.softAPgetHostname());
}

void loop(void) {

}
#include <M5Cardputer.h>
#include <WiFi.h>

WiFiServer server(80);

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
    WiFi.softAP("vampeta");
    server.begin();
}

void loop(void) {
    WiFiClient client = server.available();

    if (!client) return ;

    unsigned long timeout = millis();
    String request = "";

    while (client.connected() && millis() - timeout < 2000) {
        while (client.available()) {
            char c = client.read();
            request += c;
        }
    }
    M5Cardputer.Display.println(request);
    client.stop();
}
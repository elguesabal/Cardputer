#include <M5Cardputer.h>
#include <WiFi.h>

WiFiServer server(80);

void setup(void) {
    M5Cardputer.begin();
    WiFi.softAP("vampeta");
    server.begin();
}

void loop(void) {
    WiFiClient client = server.available();

    if (!client) return ;
    String request = "";
    delay(1000);
    while (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n') break;
    }

    M5Cardputer.Display.println(request);

    client.stop();
}
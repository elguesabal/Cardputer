#include <M5Cardputer.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

void setup(void) {
    M5Cardputer.begin();

    WiFi.softAP("vampeta");

    server.on("/", HTTP_GET, [](AsyncWebServer *res)) {
        res->send(200, "text/plain", "teste");
    }

    server.begin();
}

void loop(void) {

}

// NAO TESTEI AINDA PQ NAO INSTALEI A LIB
#include <M5Cardputer.h>
#include <WiFi.h>
#include "esp_netif.h"
#include "esp_log.h"

void setup(void) {
    M5Cardputer.begin();

    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_sta();

    WiFi.begin("ELGUESABAL", "12345678");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    M5Cardputer.Display.print("Conectado com IP: ");
    M5Cardputer.Display.println(WiFi.localIP());
}

void loop(void) {

}
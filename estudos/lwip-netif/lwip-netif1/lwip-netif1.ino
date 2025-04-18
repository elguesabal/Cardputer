#include <M5Cardputer.h>
#include <WiFi.h>

extern "C" {
    #include "esp_netif.h"
    #include "esp_wifi.h"
    #include "lwip/netif.h"
}

void setup(void) {
    M5Cardputer.begin();

    WiFi.begin("ELGUESABAL", "12345678");

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    M5Cardputer.Display.println("Conectado ao Wi-Fi!");

    esp_netif *netif = esp_netif_get_handle_from_ifkey("WIFI_STA_DEF");
    void *lwip_netif = esp_netif_get_netif_impl(netif);

    if (lwip_netif == NULL) {
        M5Cardputer.Display.print("Error");
        return ;
    }

    ip4_addr_t ip = ((struct netif*)lwip_netif)->ip_addr.u_addr.ip4;
    M5Cardputer.Display.print(ip4addr_ntoa(&ip));
}

void loop(void) {

}
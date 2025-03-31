#include <M5Cardputer.h>
#include <esp_event.h>
#include <esp_wifi.h>

uint8_t mac_ap[6];

void access_point_handler(void *buf, wifi_promiscuous_pkt_type_t type) {
    const wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t *)buf;

    if (type != WIFI_PKT_MGMT) {
        return ;
    }
    switch (pkt->payload[0]) {
        case 0x00:
            // M5Cardputer.Display.println("Association Request");
            M5Cardputer.Display.println((char *)(pkt->payload + 24));
            break;
        case 0x40:
            // M5Cardputer.Display.println("Probe Request");
            break;
        case 0x80:
            // M5Cardputer.Display.println("Beacon");
            break;
    }
}

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
    M5Cardputer.Display.println("Inicializando access point...");

    // CONFIGURANDO WIFI
    wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&wifi_config);
    esp_wifi_set_mode(WIFI_MODE_AP);

    // CONFIGURACOES DO ACCESS POINT
    wifi_config_t access_point = {};
    strcpy((char *)access_point.ap.ssid, "vampeta");
    access_point.ap.ssid_len = strlen("vampeta");
    access_point.ap.authmode = WIFI_AUTH_OPEN;
    access_point.ap.max_connection = 4;
    esp_wifi_set_config(WIFI_IF_AP, &access_point);

    esp_wifi_start();

    // PEGA O MAC DO ACCESS POINT
    esp_wifi_get_mac(WIFI_IF_AP, mac_ap);

    // AVITA O MODO PROMISCUOUS
    esp_wifi_set_promiscuous(true);
    esp_wifi_set_promiscuous_rx_cb(&access_point_handler);
}

void loop(void) {

}
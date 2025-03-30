#include <M5Cardputer.h>
#include <esp_event.h>
#include <esp_wifi.h>

uint8_t mac_ap[6];

void access_point_handler(void *buf, wifi_promiscuous_pkt_type_t type) {
    const wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t *)buf;
    const wifi_pkt_rx_ctrl_t *rx_ctrl = &pkt->rx_ctrl;

    // uint8_t *mac_dest = (uint8_t *)pkt->payload;

    // if (memcmp(mac_dest, mac_ap, 6) == 0) {
    //     M5Cardputer.Display.printf("Pacote para o AP - RSSI: %d dBm\n", rx_ctrl->rssi);
    // }

    // M5Cardputer.Display.printf("%02X:%02X:%02X:%02X:%02X:%02X\n", mac_ap[0], mac_ap[1], mac_ap[2], mac_ap[3], mac_ap[4], mac_ap[5]);
    // M5Cardputer.Display.printf("%02X:%02X:%02X:%02X:%02X:%02X\n\n", mac_dest[0], mac_dest[1], mac_dest[2], mac_dest[3], mac_dest[4], mac_dest[5]);

    if (type == WIFI_PKT_MGMT) {
        uint8_t *mac_src = (uint8_t *)(pkt->payload + 6);

        if (pkt->payload[0] == 0x00) {
            M5Cardputer.Display.println("Association Request detectado");
            M5Cardputer.Display.printf("%02X:%02X:%02X:%02X:%02X:%02X\n\n", mac_src[0], mac_src[1], mac_src[2], mac_src[3], mac_src[4], mac_src[5]);
        }

        // if (pkt->payload[0] == 0x40) {
        //     M5Cardputer.Display.printf("Connection: %02X:%02X:%02X:%02X:%02X:%02X\n", mac_src[0], mac_src[1], mac_src[2], mac_src[3], mac_src[4], mac_src[5]);
        // }

        // if (pkt->payload[0] == 0x80) {
        //     M5Cardputer.Display.println("Beacon detectado");
        // }
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
    strcpy((char *)access_point.ap.password, "12345678");
    access_point.ap.ssid_len = strlen("vampeta");
    access_point.ap.authmode = WIFI_AUTH_WPA2_PSK;
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
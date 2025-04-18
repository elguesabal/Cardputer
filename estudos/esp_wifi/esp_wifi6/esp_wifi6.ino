#include <M5Cardputer.h>
#include <esp_event.h>
#include <esp_wifi.h>

uint8_t mac_ap[6];

void access_point_handler(void *buf, wifi_promiscuous_pkt_type_t type) {
    switch (type) {
        case WIFI_PKT_MGMT:
            M5Cardputer.Display.println("Pacote de Gerenciamento");
            break;
        case WIFI_PKT_DATA:
            M5Cardputer.Display.println("Pacote de Dados");
            break;
        case WIFI_PKT_CTRL:
            M5Cardputer.Display.println("Pacote de Controle");
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
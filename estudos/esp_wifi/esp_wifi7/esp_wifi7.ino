#include <M5Cardputer.h>
#include <esp_event.h>
#include <esp_wifi.h>


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
}

void loop(void) {

}
#include <M5Cardputer.h>
#include <esp_wifi.h>
#include <esp_event.h>
#include <nvs_flash.h>

#define SSID "vampeta"
#define PASSWORD "12345678"
#define MAX_CONNECTIONS 4

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(1);

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        nvs_flash_erase();
        nvs_flash_init();
    }

    esp_netif_init();
    esp_event_loop_create_default();
    esp_netif_create_default_wifi_ap();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    wifi_config_t wifi_config = {};
    strcpy((char*)wifi_config.ap.ssid, SSID);
    strcpy((char*)wifi_config.ap.password, PASSWORD);
    wifi_config.ap.ssid_len = strlen(SSID);
    wifi_config.ap.max_connection = MAX_CONNECTIONS;
    wifi_config.ap.authmode = WIFI_AUTH_WPA_WPA2_PSK;

    if (strlen(PASSWORD) == 0) {
        wifi_config.ap.authmode = WIFI_AUTH_OPEN;
    }

    esp_wifi_set_mode(WIFI_MODE_AP);
    esp_wifi_set_config(WIFI_IF_AP, &wifi_config);
    esp_wifi_start();

    M5Cardputer.Display.printf("SSID: %s", SSID);
}

void loop(void) {

}
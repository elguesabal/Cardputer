#include <M5Cardputer.h>
#include <esp_event.h>
#include <esp_wifi.h>

void wifi_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    if (event_base != WIFI_EVENT) {
        return ;
    }
    switch (event_id) {
        case WIFI_EVENT_STA_START:
            M5Cardputer.Display.println("Conectando ao wifi...");
            esp_wifi_connect();
            break;
        case WIFI_EVENT_STA_CONNECTED:
            M5Cardputer.Display.println("Wifi conectado!");
            break;
        case WIFI_EVENT_STA_DISCONNECTED:
            M5Cardputer.Display.println("Tentando reconectar...");
            esp_wifi_connect();
            break;
    }
}

void setup(void) {
    M5Cardputer.begin();

    // CRIANDO EVENTO DE LOOP DE EVENTOS
    esp_event_loop_create_default();

    // REGISTRANDO MANIPULADORES DE EVENTOS
    esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL, NULL);

    // CONFIGURANDO WIFI
    wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&wifi_config);
    esp_wifi_set_mode(WIFI_MODE_STA);

    // CONFIGURANDO SSID E SENHA
    wifi_config_t wifi = {};
    strcpy((char *)wifi.sta.ssid, "ELGUESABAL");
    strcpy((char *)wifi.sta.password, "12345678");
    esp_wifi_set_config(WIFI_IF_STA, &wifi);

    esp_wifi_start();
}

void loop(void) {

}
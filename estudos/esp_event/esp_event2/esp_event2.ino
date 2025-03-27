#include <M5Cardputer.h>
#include <esp_wifi.h>
#include <esp_event.h>

void wifi_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    if (event_base == WIFI_EVENT) {
        switch (event_id) {
            case WIFI_EVENT_STA_START:
                M5Cardputer.Display.println("Conectando ao Wi-Fi...");
                esp_wifi_connect();
                break;
            case WIFI_EVENT_STA_CONNECTED:
                M5Cardputer.Display.println("Wi-Fi conectado!");
                break;
            case WIFI_EVENT_STA_DISCONNECTED:
                M5Cardputer.Display.println("Wi-Fi desconectado. Reconectando...");
                esp_wifi_connect();
                break;
        }
    }
}

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.println("Inicializando Wi-Fi...");
    esp_event_loop_create_default();
    esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL, NULL);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_start();
}

void loop(void) {
    M5Cardputer.Display.println("teste");
    delay(2000);
}
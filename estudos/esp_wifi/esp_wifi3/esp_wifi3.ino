#include <M5Cardputer.h>
#include <esp_event.h>
#include <esp_wifi.h>

void access_point_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    if (event_base != WIFI_EVENT) {
        return ;
    }
    switch (event_id) {
        case WIFI_EVENT_AP_START:
            M5Cardputer.Display.println("Ponto de acesso iniciado!");
            break;
        case WIFI_EVENT_AP_STOP:
            M5Cardputer.Display.println("Ponto de acesso parado!");
            break;
        case WIFI_EVENT_AP_STACONNECTED:
            M5Cardputer.Display.println("Dispositivo conectado ao AP!");
            break;
        case WIFI_EVENT_AP_STADISCONNECTED:
            M5Cardputer.Display.println("Dispositivo desconectado do AP!");
            break;
    }
}

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.println("Inicializando access point...");

    // CRIANDO EVENTO DE LOOP DE EVENTOS
    esp_event_loop_create_default();

    // REGISTRANDO MANIPULADORES DE EVENTOS
    esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &access_point_handler, NULL, NULL);

    // CONFIGURANDO WIFI
    wifi_init_config_t wifi_config = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&wifi_config);
    esp_wifi_set_mode(WIFI_MODE_AP);

    // CONFIGURACOES DO ACCESS POINT
    wifi_config_t access_point = {};
    strcpy((char *)access_point.ap.ssid, "vampeta");
    strcpy((char *)access_point.ap.password, "12345678");
    access_point.ap.ssid_len = strlen("vampeta");
    access_point.ap.max_connection = 4;
    access_point.ap.authmode = WIFI_AUTH_WPA2_PSK;
    esp_wifi_set_config(WIFI_IF_AP, &access_point);

    esp_wifi_start();
}

void loop(void) {

}
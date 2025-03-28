#include <M5Cardputer.h>
#include <esp_event.h>

// DEFININDO UMA BASE DE EVENTOS PERSONALIZADA
ESP_EVENT_DEFINE_BASE(EVENT1);
ESP_EVENT_DEFINE_BASE(EVENT2);

#define NUM 0

void event_handler(void *handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_dat) {
    if (event_base == EVENT1) {
        switch (event_id) {
            case NUM:
                M5Cardputer.Display.println("EVENT1 --> NUM");
                break;
            default:
                M5Cardputer.Display.println("EVENT1 --> default");
        }
    } else if (event_base == EVENT2) {
        switch (event_id) {
            case NUM:
                M5Cardputer.Display.println("EVENT2 --> NUM");
                break;
            default:
                M5Cardputer.Display.println("EVENT2 --> default");
        }
    }
}

void setup(void) {
    M5Cardputer.Display.begin();

    // CRIANDO UM LOOP DE EVENTOS
    esp_event_loop_create_default();

    // REGISTRANDO MANIPULADOR DE EVENTOS
    esp_event_handler_instance_register(EVENT1, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL);
    esp_event_handler_instance_register(EVENT2, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL);
}

void loop(void) {
    // POSTANDO EVENTOS PERSONALIZADOS
    esp_event_post(EVENT1, 0, NULL, 0, portMAX_DELAY);
    delay(1000);
    esp_event_post(EVENT1, 1, NULL, 0, portMAX_DELAY);
    delay(1000);
    esp_event_post(EVENT2, 0, NULL, 0, portMAX_DELAY);
    delay(1000);
    esp_event_post(EVENT2, 1, NULL, 0, portMAX_DELAY);
    delay(1000);
}
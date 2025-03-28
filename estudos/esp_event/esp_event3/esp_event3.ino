#include <M5Cardputer.h>
#include <esp_event.h>

// DEFININDO UMA BASE DE EVENTOS PERSONALIZADA
ESP_EVENT_DEFINE_BASE(EVENT);

// DEFININDO OS TIPOS DE EVENTOS
enum {
    EVENT_0,
    EVENT_1
};

void event_handler(void *handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_dat) {
    if (event_base == EVENT) {
        int *n = NULL;
        char *str = NULL;
        switch (event_id) {
            case EVENT_0:
                n = (int *)event_dat;
                M5Cardputer.Display.printf("EVENT_0 --> %d\n", *n);
                break;
            case EVENT_1:
                str = (char *)event_dat;
                M5Cardputer.Display.printf("EVENT_1 --> %s\n", str);
                break;
        }
    }
}

void setup(void) {
    M5Cardputer.begin();

    // CRIANDO UM LOOP DE EVENTOS
    esp_event_loop_create_default();

    // REGISTRANDO MANIPULADOR DE EVENTOS
    esp_event_handler_instance_register(EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL);
}

void loop(void) {
    // POSTANDO EVENTOS PERSONALIZADOS
    int n = 42;
    esp_event_post(EVENT, 0, &n, sizeof(n), portMAX_DELAY);
    delay(1000);
    char str[] = "vampeta";
    esp_event_post(EVENT, 1, str, sizeof(str), portMAX_DELAY);
    delay(1000);
}
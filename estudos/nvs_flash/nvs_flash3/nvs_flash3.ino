#include <M5Cardputer.h>
#include <nvs_flash.h>

void setup(void) {
    M5Cardputer.begin();

    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        M5Cardputer.Display.println("Erro ao iniciar");
        return ;
    }

    nvs_flash_erase();
    nvs_flash_init();
    M5Cardputer.Display.println("Particao nvs limpada");
}

void loop(void) {

}
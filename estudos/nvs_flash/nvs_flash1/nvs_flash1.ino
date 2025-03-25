#include <M5Cardputer.h>
#include <nvs_flash.h>

void setup(void) {
    M5Cardputer.begin();

    // INICIALIZA O NVS
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        M5Cardputer.Display.println("Erro da memoria");
        return ;
    } else if (err != ESP_OK) {
        M5Cardputer.Display.println("Falha ao inicializar o NVS");
        return ;
    }
    M5Cardputer.Display.println("NVS inicializado com sucesso");

    // ABRE UM NAMESPACE
    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);
    if (err != ESP_OK) {
        M5Cardputer.Display.println("Erro ao abrir o NVS");
        return ;
    }

    // SALVA UM VALOR
    int32_t counter = 42;
    err = nvs_set_i32(my_handle, "counter_key", counter);
    if (err == ESP_OK) {
        M5Cardputer.Display.println("Valor salvo com sucesso");
        nvs_commit(my_handle);
    } else {
        M5Cardputer.Display.println("Falha ao salvar o valor");
    }

    // LER O VALOR
    int32_t read_value = 0;
    err = nvs_get_i32(my_handle, "counter_key", &read_value);
    if (err == ESP_OK) {
        M5Cardputer.Display.print("Valor lido da NVS: ");
        M5Cardputer.Display.print(read_value);
    } else if (err == ESP_ERR_NVS_NOT_FOUND) {
        M5Cardputer.Display.println("Chave não encontrada");
    } else {
        M5Cardputer.Display.println("Erro ao ler o valor");
    }

    // FECHA O NVS
    nvs_close(my_handle);
}

void loop(void) {

}
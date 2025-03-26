#include <esp_log.h>

void setup(void) {
  Serial.begin(115200);
}

void loop(void) {
  Serial.println("Mensagem via Serial.println()");
  ESP_LOGI("TagExemplo", "Mensagem via ESP_LOGI");
  delay(2000);
}

// NAO CONSEGUI FAZER FUNCIONAR
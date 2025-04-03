#include <M5Cardputer.h>
#include <WiFi.h>
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/netif.h"
#include "lwip/tcp.h"

// Callback que processa pacotes recebidos
err_t packet_capture_callback(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err) {
    if (p == NULL) return ERR_OK;

    M5Cardputer.Display.print("Pacote recebido: ");
    M5Cardputer.Display.println(p->tot_len);

    // Exibe os dados do pacote em hexadecimal
    uint8_t *data = (uint8_t*) p->payload;
    for (int i = 0; i < p->tot_len; i++) {
        M5Cardputer.Display.printf("%02X ", data[i]);
        if ((i + 1) % 16 == 0) M5Cardputer.Display.println();
    }
    M5Cardputer.Display.println("\n----------------------");

    pbuf_free(p);  // Libera o buffer após a leitura
    return ERR_OK;
}

void setup() {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);

    // Conectando ao WiFi
    WiFi.softAP("vampeta");
    M5Cardputer.Display.println("Access point criado!");

    // Criando um socket raw (captura de pacotes)
    struct tcp_pcb *pcb = tcp_new();
    if (!pcb) {
        M5Cardputer.Display.println("Falha ao criar socket TCP");
        return;
    }

    // Associa a porta 80 (HTTP) ou 0 para capturar tudo
    err_t err = tcp_bind(pcb, IP_ADDR_ANY, 0);
    if (err != ERR_OK) {
        M5Cardputer.Display.println("Falha ao associar socket.");
        return;
    }

    // Define a função que será chamada ao receber pacotes
    tcp_recv(pcb, packet_capture_callback);

    M5Cardputer.Display.println("Captura de pacotes iniciada!");
}

void loop() {
    delay(100);
}

#include "header.h"

void dnsStart(void) {
    dnsServer.start(PORT_DNS, "*", WiFi.softAPIP());
}
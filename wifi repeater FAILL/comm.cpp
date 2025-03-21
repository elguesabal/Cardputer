#include "header.h"

String request(std::string url, uint16_t port, String requestClient) {
    WiFiClient req;
    if (req.connect(url.c_str(), port)) {
        req.print(requestClient);
        while (!req.available()) {
            delay(10);
        }
        String res = req.readString();
        req.stop();
        return (res);
    }
    return ("");
}
#ifndef DNS_HPP
#define DNS_HPP

#include <Arduino.h>
#include <M5GFX.h>
#include <vector>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

class Dns {
    public:
        Dns(int port, std::vector<pollfd> &fds, M5GFX *M5CARDPUTER);
        Dns(int port, std::vector<pollfd> &fds);
        ~Dns(void);

        void setPfd(void);
        void setDns(int port);
        void setBind(void);

        void requestDns(void);

    private:
        M5GFX *_display;
        struct sockaddr_in _dns{};
        struct pollfd _pfd{};
};

#endif
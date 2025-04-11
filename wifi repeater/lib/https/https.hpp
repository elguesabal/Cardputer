#ifndef HTTPS_HPP
# define HTTPS_HPP

#include <Arduino.h>
#include <M5GFX.h>
#include <vector>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

class Https {
    public:
        Https(int port, std::vector<pollfd> &fds, M5GFX *M5CARDPUTER);
        Https(int port, std::vector<pollfd> &fds);
        ~Https(void);

        void setPfd(void);
        void setHttps(int port);   
        void setBind(void);
        void setListen(void);

    private:
        M5GFX *_display;
        struct sockaddr_in _https{};
        struct pollfd _pfd{};
};

#endif
#ifndef HTTPS_HPP
# define HTTPS_HPP

#include <Arduino.h>
#include <M5GFX.h>
#include <vector>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

class Https {
    public:
        Https(int port, std::vector<pollfd> &fds);
        ~Https(void);

        void setPfd(void);
        void setHttps(int port);   
        void setBind(void);
        void setListen(void);

    private:
        struct sockaddr_in _https{};
        struct pollfd _pfd{};
};

#endif
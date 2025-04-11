#ifndef HTTP_HPP
# define HTTP_HPP

#include <Arduino.h>
#include <M5GFX.h>
#include <vector>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

class Http {
    public:
        Http(int port, std::vector<pollfd> &fds, M5GFX *M5CARDPUTER);
        Http(int port, std::vector<pollfd> &fds);
        ~Http(void);

        void setPfd(void);
        void setHttp(int port);   
        void setBind(void);
        void setListen(void);

    private:
        M5GFX *_display;
        struct sockaddr_in _http{};
        struct pollfd _pfd{};
};

#endif
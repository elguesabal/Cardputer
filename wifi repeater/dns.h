#ifndef DNS_HPP
# define DNS_HPP

class Dns {
    public:
        Dns(int port);
        ~Dns(void);

    private:
        struct sockaddr_in dns;
        struct pollfd pfd;
};

#endif
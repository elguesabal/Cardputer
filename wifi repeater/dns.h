#ifndef DNS_HPP
# define DNS_HPP

class Dns {
    public:
        Dns(int port, std::vector<pollfd> &fds);
        ~Dns(void);

        void setPfd(void);
        void setDns(int port);
        void setBind(void);
        void setListen(void);

    private:
        struct sockaddr_in _dns;
        struct pollfd _pfd;
};

#endif
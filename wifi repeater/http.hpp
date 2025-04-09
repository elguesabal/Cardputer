#ifndef HTTP_HPP
# define HTTP_HPP

class Http {
    public:
        Http(int port, std::vector<pollfd> &fds);
        ~Http(void);

        void setPfd(void);
        void setHttp(int port);   
        void setBind(void);
        void setListen(void);

    private:
        struct sockaddr_in _http{};
        struct pollfd _pfd{};
};

#endif
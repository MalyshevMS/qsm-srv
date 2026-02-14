#include "tcp/server.hpp"
#include "config.txx"
#include "ssl/ssl.hpp"
#include <print>

int main(int argc, char const *argv[]) {
    // TcpServer server;
    // server.run(QSM_PORT);
    std::println("{}", sha256("hello, world1"));
    std::println("{}", sha256("hello, world2"));
    return 0;
}

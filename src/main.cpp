#include "tcp/server.hpp"
#include "config.txx"

int main(int argc, char const *argv[]) {
    TcpServer server;
    server.run(QSM_PORT);
    return 0;
}

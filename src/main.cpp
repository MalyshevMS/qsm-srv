#include "tcp/server.hpp"
#include "config.txx"
#include "ssl/ssl.hpp"
#include <print>
#include "fs/get.hpp"
#include "fs/post.hpp"

int main(int argc, char const *argv[]) {
    // TcpServer server;
    // server.run(QSM_PORT);
    // std::println("{}", sha512("file.txt"));

    auto data = new uint8_t[QSM_BLOCK_SIZE] {
        't', 'e', 's', 't'
    };

    QSM_POST("user0", "file.txt", data);
    return 0;
}

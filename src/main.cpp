#include "tcp/server.hpp"
#include "config.txx"
#include "ssl/ssl.hpp"
#include <print>
#include "fs/get.hpp"

int main(int argc, char const *argv[]) {
    // TcpServer server;
    // server.run(QSM_PORT);
    // std::println("{}", sha512("file.txt"));

    auto data = qsmfs::get("user0", "dir.d/file.txt");
    for (int i = 0; i < QSM_1MB; i++) {
        std::print("{}", (char)data[i]);
    }
    std::println();
    delete[] data;

    auto data2 = qsmfs::get("user0", "dir2/file.txt");
    for (int i = 0; i < QSM_1MB; i++) {
        std::print("{}", (char)data2[i]);
    }
    std::println();
    delete[] data2;
    return 0;
}

#include "server.hpp"
#include "handler.hpp"
#include <SFML/Network/TcpListener.hpp>
#include <print>
#include <thread>

TcpServer::TcpServer() {}

void TcpServer::run(unsigned short port) {
    sf::TcpListener listener;

    if (listener.listen(port) != sf::Socket::Status::Done) {
        std::println("Error: couldn't listen on port {}", port);
        return;
    }

    std::println("Info: QSM Server started on port {}", port);

    while (true) {
        auto socket = std::make_shared<sf::TcpSocket>();

        if (listener.accept(*socket) != sf::Socket::Status::Done) continue;

        std::lock_guard lk(mtx);
        clients.push_back(socket);
        std::thread t {handleSock, this, socket};
        t.detach();
    }
}

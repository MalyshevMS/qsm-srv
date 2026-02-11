#include "handler.hpp"
#include "../sys/stringify.hpp"
#include <SFML/Network/IpAddress.hpp>
#include <print>
#include <string>
#include <algorithm>

void eraseClient(TcpServer *srv, ptr<sf::TcpSocket> sock) {
    std::lock_guard lk(srv->mtx);

    srv->clients.erase(
        std::remove(
            srv->clients.begin(),
            srv->clients.end(),
            sock
        ),
        srv->clients.end()
    );
}

void handleSock(TcpServer *srv, ptr<sf::TcpSocket> sock) {
    auto addr = stringify(*sock->getRemoteAddress());
    std::println("Info: new client connected from {}", addr);
    
    while(true) {
        char buff[QSM_PACKET_SIZE];
        size_t recv;

        if (sock->receive(buff, sizeof(buff), recv) != sf::Socket::Status::Done) break;

        std::string packet {buff, recv};
        std::println("Info: packet recieved from {} ({} bytes): {}", addr, recv, packet);
    }

    eraseClient(srv, sock);
    std::println("Info: client disconnected (from {})", addr);
}
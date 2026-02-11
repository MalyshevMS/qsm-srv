#include <SFML/Network.hpp>
#include "config.txx"
#include <print>

int main(int argc, char const *argv[]) {
    sf::TcpListener listener;
    auto _ = listener.listen(QSM_PORT, sf::IpAddress::LocalHost);

    sf::TcpSocket sock;
    if (listener.accept(sock) != sf::Socket::Status::Done) return 2;

    while (true) {
        char buff[QSM_PACKET_SIZE];
        size_t recieved;

        if (sock.receive(buff, sizeof(buff), recieved) != sf::Socket::Status::Done) break;

        std::string packet {buff, recieved};

        std::println("Packet recieved: {}", packet);
    }
    return 0;
}

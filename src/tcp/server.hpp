#pragma once

#include "../config.txx"
#include <vector>
#include <mutex>
#include <SFML/Network/TcpSocket.hpp>

class TcpServer {
private:
    std::vector<ptr<sf::TcpSocket>> clients;
    std::mutex mtx;
public:
    TcpServer();
    void run(unsigned short port);

    friend void eraseClient(TcpServer*, ptr<sf::TcpSocket>);
    friend void handleSock(TcpServer*, ptr<sf::TcpSocket>);
};
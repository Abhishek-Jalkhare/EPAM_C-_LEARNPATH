//
// Created by AbhishekJalkhare on 16-03-2026.
//

#include "NetworkConnection.h"
#include <iostream>
#include <utility>

struct NetworkConnection::Impl{
    std::string endpoint;
    bool connected;

    Impl(std::string  ep) : endpoint(std::move(ep)), connected(false) {
        // Simulate opening a socket or connection
        connected = true;
        std::cout << "[Impl] Connected to " << endpoint << std::endl;
    }
    ~Impl() {
        // Simulate closing the socket/connection
        if (connected) {
            std::cout << "[Impl] Connection to " << endpoint << " closed" << std::endl;
        }
    }
    void sendData(const std::string& data) {
        if (!connected) {
            std::cerr << "[Impl] Not connected!\n";
            return;
        }
        std::cout << "[Impl] Sending data to " << endpoint << ": " << data << std::endl;
    }
};

NetworkConnection::NetworkConnection(const std::string& ep): impl(std::make_unique<Impl>(ep)) {

}



bool NetworkConnection::isConnected() const {
    return impl->connected;
}

void NetworkConnection::sendData(const std::string& data) {
    impl->sendData(data);
}

//
// Created by AbhishekJalkhare on 16-03-2026.
//

#ifndef CPPLEARNING_NETWORKCONNECTION_H
#define CPPLEARNING_NETWORKCONNECTION_H
#include <memory>
#include<string>


class NetworkConnection {
public:
    NetworkConnection(const std::string& ep);
    ~NetworkConnection() = default;
    bool isConnected() const;
    void sendData(const std::string& data);

private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};


#endif //CPPLEARNING_NETWORKCONNECTION_H
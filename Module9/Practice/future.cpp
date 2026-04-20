//
// Created by AbhishekJalkhare on 13-04-2026.
//

#include <future>
#include <iostream>

int main(int argc, char *argv[]) {
    std::future<int> f = std::async([]() {
        return 12;
    });
    std::cout<<f.get()<<std::endl;
    //f.get();
     f.wait();
}

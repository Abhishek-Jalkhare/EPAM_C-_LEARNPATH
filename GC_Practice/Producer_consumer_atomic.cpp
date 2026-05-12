//
// Created by AbhishekJalkhare on 12-05-2026.
//
#include <iostream>
#include <atomic>
#include <queue>
#include <syncstream>
#include <thread>


std::vector<int> buffer(16);
constexpr size_t size = 16;
std::atomic<size_t> front = 0;
std::atomic<size_t> end = 0;
size_t items = 120000;


void producer() {
    size_t temp = items;

    while (temp) {
        const size_t f = front.load(std::memory_order::acquire); // producer do not own front that is consumer
        // changes it so it has to acquire it or it may get false value
        const size_t e = end.load(std::memory_order::relaxed);
        if ((e + 1) % size == f) continue;
        buffer[e%size] = rand()%100;
        std::cout<<"Produced : "<<buffer[e%size]<<std::endl;
        end.fetch_add(1 ,std::memory_order_release);
        temp--;
    }

}

void consumer() {
    size_t temp = items;

    while (temp) {
        const size_t f = front.load(std::memory_order::relaxed);
        const size_t e = end.load(std::memory_order::acquire);
        if (f == end) continue;
        std::cout<<"consumed : "<<buffer[f%size]<<std::endl;
        front.fetch_add(1 , std::memory_order::release);
        temp--;
    }
}

int main(int argc, char *argv[]) {
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}

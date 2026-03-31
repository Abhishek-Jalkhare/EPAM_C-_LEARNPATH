//
// Created by AbhishekJalkhare on 16-03-2026.
//

#include "bigdata.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

struct bigdata::Impl{
std::vector<int> bigVector;
std::map<std::string, int> bigMap;
std::string name;

 Impl() {
    bigVector.resize(1'000'000, 42);
    name = "BigData resource";
    bigMap["test"] = 99;
    std::cout << "[BigData::Impl] constructed with heavy data\n";
}
~Impl() {
    std::cout << "[BigData::Impl] destroyed\n";
}
};

bigdata::bigdata() : impl(std::make_unique<Impl>()) {}
bigdata::~bigdata() = default;
void bigdata::process() {
    impl->bigVector[0]++;
    impl->bigMap["process"] = int(impl->bigVector[0]);
    std::cout << "Processing " << impl->name << ": " << impl->bigVector[0] << std::endl;
}


size_t bigdata::getSize() const {
    return impl->bigVector.size();
}


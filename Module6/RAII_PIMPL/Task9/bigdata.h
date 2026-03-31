//
// Created by AbhishekJalkhare on 16-03-2026.
//

#ifndef CPPLEARNING_BIGDATA_H
#define CPPLEARNING_BIGDATA_H
#include <memory>

class bigdata {
public:
    bigdata();
    ~bigdata();

    void process();
    size_t getSize() const;
private:
    struct Impl;                // Forward declaration only!
    std::unique_ptr<Impl> impl;
};


#endif //CPPLEARNING_BIGDATA_H
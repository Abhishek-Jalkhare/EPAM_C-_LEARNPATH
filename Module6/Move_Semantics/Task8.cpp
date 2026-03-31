//
// Created by AbhishekJalkhare on 11-03-2026.
//
//
// Created by AbhishekJalkhare on 10-03-2026.
//
#include <cstring>
#include <iostream>
#include <vector>

// Rule of 0 Demonstration:
// This class follows the "Rule of 0" - a modern C++ best practice.
// Since all members (std::vector, std::string) are self-managing types,
// we don't need to define:
//   - Destructor
//   - Copy constructor
//   - Copy assignment operator
//   - Move constructor
//   - Move assignment operator
// The compiler-generated versions are correct, safe, and efficient.
class Wrapper {
public:
    std::vector<int> data;
    std::string label;

    Wrapper(std::string l, std::initializer_list<int> il)
        : data(il), label(std::move(l)) {}

    void print(const char* tag) const {
        std::cout << tag << " label: " << label << " data: ";
        for (auto x : data) std::cout << x << " ";
        std::cout << " [data : " << static_cast<const void*>(data.data()) << "]" << std::endl;
    }
};

class ManualRuleOf3 {
    char* buf;
public:
    explicit ManualRuleOf3(const char* str = "") {
        buf = new char[strlen(str)+1];
        strcpy(buf,str);
    }
    ManualRuleOf3(const ManualRuleOf3& other) {
        const size_t size = strlen(other.buf)+1;
        buf = new char[size];
        strcpy(buf , other.buf);
    }

    ManualRuleOf3& operator=(const ManualRuleOf3& other) {
        if (this == &other) return *this;
        delete[]buf;
        const size_t size = strlen(other.buf)+1;
        buf = new char[size];
        strcpy(buf , other.buf);
        return *this;
    }
    ~ManualRuleOf3() {
        delete[] buf;
    }
};


int main() {
    Wrapper w1("first", {1,2,3});
    w1.print("w1:");

    Wrapper w2 = w1;        // Copy
    w2.label = "copy";
    w2.print("w2:");
    Wrapper w3 = std::move(w1); // Move
    w3.label = "moved";
    w3.print("w3:");
    w1.print("w1 after move:"); // w1's data is valid but unspecified (empty/moved-from)

    return 0;
}

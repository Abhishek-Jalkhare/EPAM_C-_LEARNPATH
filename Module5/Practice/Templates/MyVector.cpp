// Online C++ compiler to run C++ program online
#include <iostream>
#include <memory>
template<typename T>
class vectorr{
    std::unique_ptr<T[]> up;
    size_t n;
public :
    vectorr(const size_t n) : up(std::make_unique<T[]>(n)) , n(n){

    }

    T& operator[] (size_t n) {
        if (this->n <= n) throw std::out_of_range("out of bound");
        return up[n];
    }
    const T& operator[] (size_t n)const{
        if (this->n <= n) throw std::out_of_range("out of bound");
        return up[n];
    }


};

int main() {
    // Write C++ code here

    vectorr<int> vec(10);
    vec[0] = 1;
    std::cout<<vec[0]<<std::endl;
    return 0;
}
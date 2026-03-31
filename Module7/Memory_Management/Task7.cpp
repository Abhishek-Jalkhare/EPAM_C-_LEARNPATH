//
// Created by AbhishekJalkhare on 18-03-2026.
//

#include <iostream>
#include<cstdio>
#include <memory>

int main(int argc, char* argv[]) {
    FILE* file = fopen("log.txt" , "w");
    if (file == nullptr) {
        std::cout << "Failed to open File";
        return 1;
    }
    auto deleter = [](FILE* f){
        if (f) {
            fclose(f);
            std::cout << "File closed by custom deleter.\n";
        }
    };
    std::unique_ptr<FILE , decltype(deleter)>filePtr  {file , deleter} ;
    fprintf(filePtr.get(), "Log started\n"); // fprintf() writes formatted input
    // to file stream
}
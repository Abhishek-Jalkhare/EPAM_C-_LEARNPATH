//
// Created by AbhishekJalkhare on 22-04-2026.
//
#include<iostream>
#include <csignal>
#include<cstring>
#ifdef __linux__
#include <unistd.h>
#include <execinfo.h>
#endif

void crashHandler(int sig) {
    const char* msg = "Caught signal SIGSEGV \n";
#ifdef __linux__
    write(STDERR_FILENO , msg , strlen(msg));
    void* arr[10];
    size_t size = backtrace(arr , 10);
    backtrace_symbols_fd( arr , size , STDERR_FILENO);
#endif
    _exit(1);
}

int main(int argc, char *argv[]) {
    signal(SIGSEGV , crashHandler);
    int *ptr = nullptr;
    *ptr = 10;
    return 0;
}

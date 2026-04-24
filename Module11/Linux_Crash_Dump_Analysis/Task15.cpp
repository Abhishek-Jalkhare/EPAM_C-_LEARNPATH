//
// Created by AbhishekJalkhare on 22-04-2026.
//
#include <csignal>
#include <iostream>
#include <cstdlib>
void handler(int sig) {
    std::cerr << "Crash: received signal " << sig << std::endl;
    // 1. Restore the Default behavior (SIG_DFL)
    // This tells the OS: "I'm done, you handle the next one normally."
    signal(sig, SIG_DFL);

    // 2. Re-trigger the signal
    // Now when you raise it, the OS will see there is no custom handler
    // and perform the standard action (Terminate + Core Dump).
    std::raise(sig);
}
int main(int argc, char** argv) {
    signal(SIGSEGV, handler);
    signal(SIGFPE, handler);
    // ... call buggy logic here
    int * ptr = nullptr;
    *ptr = 10;

    return 0;
}
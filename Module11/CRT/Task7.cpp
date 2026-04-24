#ifdef _WIN32
#include <crtdbg.h>
#endif
#include <iostream>

int main() {
#ifdef _WIN32
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // Let's assume allocation #45 is suspicious (from previous leak report)
    _CrtSetBreakAlloc(161); // BREAK at allocation #45
#endif

    int* a = new int(10);
    double* b = new double(3.14);
    char* c = new char[100];
    int* d = new int[20];

    std::cout << "Allocated several objects, running..." << std::endl;

    // Intentionally leak some pointers
    // delete a; // not deleted
    delete b;
    delete[] c;
    delete[] d;

    return 0;
}

#include <iostream>
#include <Windows.h>

typedef std::string(*MD5)(std::string);

int main() {
    HINSTANCE hDLL = LoadLibrary(TEXT("hash.dll"));
    if (hDLL == NULL) {
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }

    MD5 hash = (MD5)GetProcAddress(hDLL, "MD5");
    if (hash == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::string data = "test";
    std::cout<<hash(data)<<"\n";
    FreeLibrary(hDLL);
    return 0;
}
#include <iostream>
#include <Windows.h>

typedef std::string(*MD5)(std::string);
typedef std::string(*SHA256)(std::string);
typedef std::string(*SHA1)(std::string);
typedef std::string(*MD2)(std::string);
typedef std::string(*MD4)(std::string);
typedef std::string(*SHA384)(std::string);
typedef std::string(*SHA512)(std::string);
int main() {
    HINSTANCE hDLL = LoadLibrary(TEXT("x-hash.dll"));
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
    std::cout<<"md5 = "<<hash(data)<<"\n";
    SHA256 SHA256_ = (SHA256)GetProcAddress(hDLL, "sha256");
    if (SHA256_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<"sha256 = "<<SHA256_(data)<<"\n";
    SHA1 SHA1_ = (SHA1)GetProcAddress(hDLL, "sha1");
    if (SHA1_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<SHA1_(data)<<"\n";
    MD2 MD2_ = (MD2)GetProcAddress(hDLL, "md2");
    if (MD2_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<MD2_(data)<<"\n";
    MD4 MD4_ = (MD4)GetProcAddress(hDLL, "md4");
    if (MD4_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<"md4 = "<<MD4_(data)<<"\n";
    SHA384 SHA384_ = (SHA384)GetProcAddress(hDLL, "sha384");
    if (SHA384_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<"sha384 = "<<SHA384_(data)<<"\n";
    SHA512 SHA512_ = (SHA512)GetProcAddress(hDLL, "sha512");
    if (SHA512_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<"sha512 = "<<SHA512_(data)<<"\n";
    FreeLibrary(hDLL);
    return 0;
}
# X-hash
Hash implementation for use in different languages
## Developed by Codelogy
Version : 1.0
</br>
Telegram Channel: <a href="https://t.me/codelogy"> @CodeLogy </a>
# Donate
Tether (TRC20): TFh9cM5eCsdXZgv3wdkhtiG1Hvddh48LAi <br>
Bitcoin: bc1q3p98yqkagmee8zrps46yqd6uvun22ghk47cvn2 <br>
Tron: TFh9cM5eCsdXZgv3wdkhtiG1Hvddh48LAi 
# Supported hashes
<pre><code>
- MD2
- MD5
- MD4
- SHA256
- SHA384 
- SHA512
- SHA1
</pre></code>
# OS
Windows
## Example
Example of using x-hash in c++<br>
<pre><code>
typedef std::string(*MD5)(std::string);
typedef std::string(*SHA256)(std::string);
typedef std::string(*SHA1)(std::string);
typedef std::string(*MD2)(std::string);
typedef std::string(*MD4)(std::string);
typedef std::string(*SHA384)(std::string);
typedef std::string(*SHA512)(std::string);
int main() {
	//Load the dll
    HINSTANCE hDLL = LoadLibrary(TEXT("x-hash.dll"));
    if (hDLL == NULL) {
		//If a problem occurs in loading the dll, an error will be displayed and the program will exit
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }
	// function for hash md5 Input received Input received
    MD5 hash = (MD5)GetProcAddress(hDLL, "MD5");
    if (hash == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::string data = "test";
	// Convert test string to md5 hash
    std::cout<<"md5 = "<<hash(data)<<"\n";
	// function for hash sha256 Input received Input received
    SHA256 SHA256_ = (SHA256)GetProcAddress(hDLL, "sha256");
    if (SHA256_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<"sha256 = "<<SHA256_(data)<<"\n";
	// function for hash sha1 Input received Input received
    SHA1 SHA1_ = (SHA1)GetProcAddress(hDLL, "sha1");
    if (SHA1_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<SHA1_(data)<<"\n";
	// function for hash md2 Input received Input received
    MD2 MD2_ = (MD2)GetProcAddress(hDLL, "md2");
    if (MD2_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<MD2_(data)<<"\n";
	// function for hash md4 Input received Input received
    MD4 MD4_ = (MD4)GetProcAddress(hDLL, "md4");
    if (MD4_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<"md4 = "<<MD4_(data)<<"\n";
	// function for hash sha384 Input received Input received
    SHA384 SHA384_ = (SHA384)GetProcAddress(hDLL, "sha384");
    if (SHA384_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<"sha384 = "<<SHA384_(data)<<"\n";
	// function for hash sha512 Input received Input received
    SHA512 SHA512_ = (SHA512)GetProcAddress(hDLL, "sha512");
    if (SHA512_ == NULL) {
        std::cerr << "Failed to get function pointer" << std::endl;
        return 1;
    }
    std::cout<<"sha512 = "<<SHA512_(data)<<"\n";
    FreeLibrary(hDLL);
    return 0;
}
</pre></code>

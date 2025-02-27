/* this code is not a part of the project
this code is only for teasting or leaiign parpases :)*/



#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(str.c_str()), str.length(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::string hashed_password = sha256(password);
    std::cout << "Hashed Password: " << hashed_password << std::endl;
    
    return 0;
}

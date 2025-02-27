#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include <string>

std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH]; // Array to store hash output
    SHA256(reinterpret_cast<const unsigned char*>(str.c_str()), str.length(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include <openssl/sha.h>

#if defined(_MSC_VER)
    #define FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
    #define FORCE_INLINE inline __attribute__((always_inline))
#else
    #define FORCE_INLINE inline
#endif

FORCE_INLINE std::string encryptPassword(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.length(), hash);
    
    std::string encrypted;
    for (unsigned char c : hash) {
        char buffer[3];
        snprintf(buffer, sizeof(buffer), "%02x", c);
        encrypted += buffer;
    }
    return encrypted;
}

#endif // ENCRYPTION_H

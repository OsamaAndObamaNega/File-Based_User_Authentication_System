#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

class UserRegistration{
protected:
    std::string* UserName, email, password;
public:

    std::string getUsername(){
        try 
        {
            std::string input;
            while(true) {
                std::cout << "Enter ur userName: ";
                std::cin >> input;
                if(input.find(' ') == std::string::npos && std::isalpha(input[0]) && input.length() <= 18) {
                    break;
                }
                std::cout << "Invalid username. Please enter a username without spaces, special characters and less than 19 characters: ";
            }
            return input;
        } catch (const std::exception& e) {
            std::cerr << "An error occurred: " << e.what() << '\n';
            return "";
        }
    }
    
    std::string getEmail() {
        std::string input;
        
        while (true) {
            std::cout << "\nEnter your email: ";
            std::cin >> input;
    
            // Check if input contains exactly one "@gmail.com" at the end
            size_t atPos = input.find("@gmail.com");
            if (atPos != std::string::npos && atPos == input.length() - 10) {
                std::string name = input.substr(0, atPos); // Extract username part
    
                // Check if name is not empty, has no spaces, and starts with a letter
                if (!name.empty() && name.find(' ') == std::string::npos && std::isalpha(name[0])) {
                    return input; // Email is valid
                }
            }
            
            std::cout << "Invalid email! Please enter a valid Gmail address in the format 'username@gmail.com'.\n";
        }
    }
    
    
    
    std::string sha256(const std::string& str) {
        unsigned char hash[SHA256_DIGEST_LENGTH]; // Array to store hash output
        SHA256(reinterpret_cast<const unsigned char*>(str.c_str()), str.length(), hash);

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
        }
        return ss.str();
    }
    
};


int main(){
    

    return 0;
}


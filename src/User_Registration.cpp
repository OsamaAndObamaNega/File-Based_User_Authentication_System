#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>
#include <string>
// #include "User Registration.h"

class UserRegistration{
protected:
    std::string* UserName, *gmail, *password;
public:

    UserRegistration(std::string username, std::string gmail, std::string password) : 
        UserName(new std::string(username)), gmail(new std::string(gmail)), password(new std::string(password))
    {
        std::cout << "user crated\n";
    }

    
    void printUserData(){
        std::cout << "username: " << *UserName << std::endl;
        std::cout << "gmail: " << *gmail << std::endl;
        std::cout << "password: " << *password << std::endl;
    }
    
    ~UserRegistration(){
        delete UserName;
        delete gmail;
        delete password;
    }
};


class UsernameEmailEtc{
public:

    static std::string getUsername(){
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
    
    static std::string getgmail() {
        std::string input;
        
        while (true) {
            std::cout << "\nEnter your gmail: ";
            std::cin >> input;
    
            // Check if input contains exactly one "@gmail.com" at the end
            size_t atPos = input.find("@gmail.com");
            if (atPos != std::string::npos && atPos == input.length() - 10) {
                std::string name = input.substr(0, atPos); // Extract username part
    
                // Check if name is not empty, has no spaces, and starts with a letter
                if (!name.empty() && name.find(' ') == std::string::npos && std::isalpha(name[0])) {
                    return input; // gmail is valid
                }
            }
            
            std::cout << "Invalid gmail! Please enter a valid Gmail address in the format 'username@gmail.com'.\n";
        }
    }

    static std::string getPassword() {
        std::string input;

        while (true) {
            std::cout << "\nEnter your password: ";
            std::cin >> input;
            
            // Check if password is not empty, has no spaces, and is between 9 and 199 characters long
            if (!input.empty() && input.find(' ') == std::string::npos && input.length() > 8 && input.length() < 200) {
                return input; // Password is valid
            }
            
            std::cout << "Invalid password! Please enter a password with no spaces and between 9 and 199 characters.\n";
        }
    }
};

int main(){

    UserRegistration user(UsernameEmailEtc::getUsername(), UsernameEmailEtc::getgmail(), UsernameEmailEtc::getPassword());

    user.printUserData();

}


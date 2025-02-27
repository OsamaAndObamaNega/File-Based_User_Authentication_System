#include <string>
class UserRegistration{
    protected:
        std::string* UserName, *email, *password;
    public:
        UserRegistration(std::string username, std::string gmail, std::string password);
};


class UsernameEmailEtc{
public:
    static std::string getUsername();
    static std::string getgmail();
    static std::string getPassword();
};
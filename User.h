#ifndef USER_H
#define USER_H

#include <iostream>

class User
{
    int id = 0;
    std::string login = "";
    std::string password = "";
    std::string firstName = "";
    std::string lastName = "";

public:
    void setId(int newId);
    void setLogin(std::string newLogin);
    void setPassword(std::string newPassword);
    void setFirstName(std::string newFirstName);
    void setLastName(std::string newLastName);

    int getId();
    std::string getLogin();
    std::string getPassword();
    std::string getFirstName();
    std::string getLastName();
};

#endif

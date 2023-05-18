#include "User.h"

void User::setId(int newId)
{
    if ( newId >= 0 )
        id = newId;
}

void User::setLogin(std::string newLogin)
{
    login = newLogin;
}

void User::setPassword(std::string newPassword)
{
    password = newPassword;
}

void User::setFirstName(std::string newFirstName)
{
    firstName = newFirstName;
}

void User::setLastName(std::string newLastName)
{
    lastName = newLastName;
}

int User::getId()
{
    return id;
}

std::string User::getLogin()
{
    return login;
}

std::string User::getPassword()
{
    return password;
}

std::string User::getFirstName()
{
    return firstName;
}

std::string User::getLastName()
{
    return lastName;
}

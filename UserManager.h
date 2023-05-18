#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib> // pause
#include <fstream>
#include <sstream>
#include "User.h"
#include "UsersFile.h"

class UserManager
{
    int loggedUserId;
    std::vector <User> users;
    UsersFile usersFile;

    bool loginExists(std::string login);
    int getNewUserId();
    User getNewUserData();

public:
    UserManager(std::string usersFileName) : usersFile(usersFileName)
    {
        loggedUserId = 0;
        users = usersFile.loadUsersFromFile();
    };
    void userRegistration();
    void userLogin();
    bool userIsLogged();
    void userLogout();
    void userPasswordChange();
    int getLoggedUserId();
};

#endif

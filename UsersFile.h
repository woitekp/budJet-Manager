#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <fstream>

#include "XMLFile.h"
#include "User.h"

#include "Markup.h"

class UsersFile : public XMLFile
{
    User getUserData(CMarkup& xml);

public:
    UsersFile(std::string UsersFileName) : XMLFile(UsersFileName) {};
    void addUserToFile(User user);
    std::vector<User> loadUsersFromFile();
    void userPasswordChange(User userToEdit);
};

#endif

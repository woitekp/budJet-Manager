#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

#include "UsersFile.h"
#include "Markup.h"


void UsersFile::addUserToFile(User user)
{
    CMarkup xml;
    bool fileExists = xml.Load(FILE_NAME);

    if ( ! fileExists ) {
        xml.AddElem("users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("user");
    xml.IntoElem();
    xml.AddElem("id", user.getId());
    xml.AddElem("firstName", user.getFirstName());
    xml.AddElem("lastName", user.getLastName());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.Save(FILE_NAME);
}

User UsersFile::getUserData(CMarkup& xml)
{
    User user;
    xml.IntoElem();

    xml.FindElem("id");
    std::string id = xml.GetData();
    user.setId(atoi(id.c_str()));

    xml.FindElem("login");
    user.setLogin(xml.GetData());

    xml.FindElem("password");
    user.setPassword(xml.GetData());

    xml.OutOfElem();
    return user;
}

std::vector<User> UsersFile::loadUsersFromFile()
{
    std::vector<User> users;
    User user;
    CMarkup xml;
    bool fileExists = xml.Load( FILE_NAME );

    if ( fileExists )
    {
        if (xml.FindElem("users"))
        {
            xml.IntoElem();
            while (xml.FindElem("user"))
            {
                users.push_back(getUserData(xml));
            }
        }
    }

    return users;
}

void UsersFile::userPasswordChange(User userToEdit)
{
    int userToEditId = userToEdit.getId();
    User user;
    CMarkup xml;
    bool fileExists = xml.Load( FILE_NAME );

    if ( ! fileExists )
    {
        std::cout << "unexpected error";
        Sleep(3000);
        return;
    }
    else
    {
        if ( ! xml.FindElem("users") )
        {
            std::cout << "unexpected error";
            Sleep(3000);
            return;
        }
        else
        {
            xml.IntoElem();
            while (xml.FindElem("user"))
            {
                user = getUserData(xml);
                if (user.getId() == userToEditId)
                {
                    xml.FindElem("password");
                    xml.IntoElem();
                    xml.SetData(userToEdit.getPassword());
                    xml.Save( FILE_NAME );
                    return;
                }
            }
        }
    }
}

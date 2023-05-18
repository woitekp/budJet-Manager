#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = getNewUserData();

    users.push_back(user);

    usersFile.addUserToFile(user);

    std::cout << std::endl << "Account created successfully" << std::endl << std::endl;
    system("pause");
}

User UserManager::getNewUserData()
{
    User user;

    user.setId(getNewUserId());

    std::string firstName;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    user.setFirstName(firstName);

    std::string lastName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    user.setLastName(lastName);

    std::string login;
    do
    {
        std::cout << "Enter login: ";
        std::cin >> login;
        user.setLogin(login);
    } while (loginExists(user.getLogin()));

    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if ( users.empty() )
        { return 1; }
    else
        { return users.back().getId() + 1; }
}

bool UserManager::loginExists(std::string login)
{
    for (int i = 0, usersCount = users.size(); i < usersCount; i++)
    {
        if (users[i].getLogin() == login)
        {
            std::cout << std::endl << "The given login already exists. Choose different login\n" << std::endl;
            return true;
        }
    }
    return false;
}

void UserManager::userLogin()
{
    std::string login = "";
    std::string password = "";
    std::cout << "Enter login: ";
    std::cin >> login;
    for (int i = 0, usersCount = users.size(); i < usersCount; i++)
    {
        if (users[i].getLogin() == login)
        {
            for (int tries = 3; tries > 0; tries--)
            {
                std::cout << "\nEnter password ("<< tries << " tries remained): ";
                std::cin >> password;
                if (users[i].getPassword() == password)
                {
                    loggedUserId = users[i].getId();
                    return;
                }
            }
            Sleep(5000); // block program for safety reasons
            loggedUserId = 0;
            return;
        }
    }
    std::cout << "\nThere is no user with the given login\n";
    system("pause");
    loggedUserId = 0;
}

bool UserManager::userIsLogged()
{
    return loggedUserId;
}

void UserManager::userLogout()
{
    loggedUserId = 0;
}

void UserManager::userPasswordChange ()
{
    std::string password = "";
    std::cout << "Enter new password: ";
    std::cin >> password;
    int indexOfUserToEdit = -1;
    for (int i = 0, usersCount = users.size(); i < usersCount; i++)
    {
        if (users[i].getId() == loggedUserId)
        {
            users[i].setPassword(password);
            indexOfUserToEdit = i;
            break;
        }
    }
    usersFile.userPasswordChange(users[indexOfUserToEdit]);
    std::cout << "\nChanges saved\n";
    system("pause");
}

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

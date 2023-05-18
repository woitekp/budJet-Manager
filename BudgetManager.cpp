#include "BudgetManager.h"

void BudgetManager::usersMenu()
{
    char userChoice;
    while (true)
    {
        system("cls");
        std::cout << "1. Sign in\n";
        std::cout << "2. Register\n";
        std::cout << "3. Exit\n";
        std::cin >> userChoice;
        switch (userChoice)
        {
            case '1':
                {
                    userLogin();
                    if (userIsLogged())
                        {budgetManagerMenu();}
                    break;
                }
            case '2': userRegistration(); break;
            case '3': return;
        }
    }
}

void BudgetManager::budgetManagerMenu ()
{
    char userChoice;
    while (true) {
        system("cls");
        std::cout << "1. Add income\n";
        std::cout << "2. Add expense\n";
        std::cout << "3. Current month balance\n";
        std::cout << "4. Last month balance\n";
        std::cout << "5. User period balance\n";
        std::cout << "6. Change password\n";
        std::cout << "9. Logout\n";
        std::cin >> userChoice;
        switch (userChoice)
        {
            case '1': addIncome(); break;
            case '2': addExpense(); break;
            case '3': getCurrentMonthBalance(); break;
            case '4': getLastMonthBalance(); break;
            case '5': getGivenPeriodBalance(); break;
            case '6': userPasswordChange(); break;
            case '9': userLogout() ;return;
        }
    }
}

void BudgetManager::userRegistration()
{
    userManager.userRegistration();
}

void BudgetManager::userLogin()
{
    userManager.userLogin();
    int loggedUserId = userManager.getLoggedUserId();
    if (loggedUserId > 0)
    {
        balanceManager = new BalanceManager(loggedUserId, INCOMES_FILE_NAME, EXPENSES_FILE_NAME);
    }
}

void BudgetManager::userLogout()
{
    userManager.userLogout();
}

void BudgetManager::userPasswordChange()
{
    userManager.userPasswordChange();
}

bool BudgetManager::userIsLogged()
{
    return userManager.userIsLogged();
}

void BudgetManager::addIncome()
{
    balanceManager->addIncome();
}

void BudgetManager::addExpense()
{
    balanceManager->addExpense();
}

void BudgetManager::getCurrentMonthBalance()
{
    balanceManager->getCurrentMonthBalance();
}

void BudgetManager::getLastMonthBalance()
{
    balanceManager->getLastMonthBalance();
}

void BudgetManager::getGivenPeriodBalance()
{
    std::cout << "Enter start date. ";
    std::string startDate = DatesHandler::getDateFromUser();

    std::cout << "Enter end date. ";
    std::string endDate = DatesHandler::getDateFromUser(startDate);

    balanceManager->getGivenPeriodBalance(startDate, endDate);
}

#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "BalanceManager.h"

class BudgetManager
{
    UserManager userManager;
    BalanceManager *balanceManager;

    const std::string INCOMES_FILE_NAME;
    const std::string EXPENSES_FILE_NAME;

    void usersMenu();

    void userRegistration();
    void userLogin();
    void userLogout();
    void userPasswordChange();
    bool userIsLogged();

    void budgetManagerMenu();

    void addIncome();
    void addExpense();

    void getCurrentMonthBalance();
    void getLastMonthBalance();
    void getGivenPeriodBalance();

public:
    BudgetManager(std::string usersFileName, std::string incomesFileName, std::string expensesFileName)
        : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
    {
        balanceManager = NULL; // empty initialization
        usersMenu();
    };
    ~BudgetManager()
    {
        delete balanceManager;
        balanceManager = NULL;
    }

};

#endif

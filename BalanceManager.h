#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <Windows.h>

#include "TransactionsManager.h"

class BalanceManager
{
    TransactionsManager incomesManager;
    TransactionsManager expensesManager;

public:
    BalanceManager(int loggedUserId, std::string incomesFileName, std::string expensesFileName)
    : incomesManager(loggedUserId, incomesFileName), expensesManager(loggedUserId, expensesFileName)
    {};

    void addIncome();
    void addExpense();
    void getCurrentMonthBalance();
    void getLastMonthBalance();
    void getGivenPeriodBalance(std::string startDate, std::string endDate);

};
#endif

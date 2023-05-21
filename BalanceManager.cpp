#include "BalanceManager.h"

void BalanceManager::addIncome()
{
    incomesManager.addTransaction();
}

void BalanceManager::addExpense()
{
    expensesManager.addTransaction();
}

void BalanceManager::getGivenPeriodBalance(std::string startDate, std::string endDate)
{
    std::cout << "\nIncomes:\n\n";
    double incomesSum = incomesManager.getGivenPeriodTransactions(startDate, endDate);
    system("pause");

    std::cout << "\n\nExpenses:\n\n";
    double expensesSum = expensesManager.getGivenPeriodTransactions(startDate, endDate);
    system("pause");

    std::cout << "\n\nSum of your incomes is: " << incomesSum << "\n";
    std::cout << "Sum of your expenses is: " << expensesSum << "\n";
    std::cout << "Your balance in period from " << startDate << " to " << endDate << " is: " << incomesSum-expensesSum << "\n\n";
    system("pause");
}

void BalanceManager::getCurrentMonthBalance()
{
    getGivenPeriodBalance(DatesHandler::getCurrentMonthFirstDay(), DatesHandler::getCurrentMonthLastDay());
}

void BalanceManager::getLastMonthBalance()
{
    getGivenPeriodBalance(DatesHandler::getLastMonthFirstDay(), DatesHandler::getLastMonthLastDay());
}

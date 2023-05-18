#ifndef TRANSACTIONSMANAGER_H
#define TRANSACTIONSMANAGER_H

#include <algorithm> // sort()
#include <vector>
#include <iostream>
#include <Windows.h>

#include "TransactionsFile.h"
#include "Transaction.h"
#include "DatesHandler.h"
#include "AuxiliaryMethods.h"

class TransactionsManager
{
    const int LOGGED_USER_ID;
    std::vector <Transaction> transactions;
    TransactionsFile transactionsFile;

    Transaction getTransactionDataFromUser();

    static bool CompareTransactionsByDate (Transaction t1, Transaction t2);

public:
    TransactionsManager(int loggedUserId, std::string transactionsFileName)
        : LOGGED_USER_ID(loggedUserId), transactionsFile(transactionsFileName)
        {
            transactions = transactionsFile.loadTransactionsOfUser(LOGGED_USER_ID);
        };

    void addTransaction();
    float getGivenPeriodTransactions(std::string startDate, std::string endDate);
};
#endif

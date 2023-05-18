#ifndef TRANSACTIONSFILE_H
#define TRANSACTIONSFILE_H

#include <iostream>
#include <vector>
#include <string>
//#include <Windows.h>

#include "XMLFile.h"
#include "Transaction.h"

#include "Markup.h"

class TransactionsFile : public XMLFile
{
    int lastTransactionId = 0;
    Transaction getTransactionData(CMarkup& xml);

public:
    TransactionsFile(std::string TransactionsFileName) : XMLFile(TransactionsFileName) {};
    std::vector <Transaction> loadTransactionsOfUser(int userId);
    void addTransactionToFile(Transaction transaction);
    int getLastTransactionId();
};

#endif

#include "TransactionsFile.h"

Transaction TransactionsFile::getTransactionData(CMarkup& xml)
{
    Transaction transaction;

    xml.IntoElem();

    xml.FindElem("id");
    std::string id = xml.GetData();
    transaction.setId(atoi(id.c_str()));

    xml.FindElem("userId");
    std::string userId = xml.GetData();
    transaction.setUserId(atoi(userId.c_str()));

    xml.FindElem("date");
    transaction.setDate(xml.GetData());

    xml.FindElem("category");
    transaction.setCategory(xml.GetData());

    xml.FindElem("amount");
    transaction.setAmount(xml.GetData());

    xml.OutOfElem();

    return transaction;
}

std::vector<Transaction> TransactionsFile::loadTransactionsOfUser(int userId)
{
    std::vector <Transaction> transactions;
    Transaction transaction;

    CMarkup xml;
    bool fileExists = xml.Load(FILE_NAME);
    if (fileExists)
    {
        if (xml.FindElem(MAIN_TAG))
        {
            xml.IntoElem();
            while (xml.FindElem("transaction"))
            {
                transaction = getTransactionData(xml);
                if (transaction.getUserId() == userId)
                    {transactions.push_back(transaction);}
            }
            lastTransactionId = transaction.getId();
        }
    }
    return transactions;
}

void TransactionsFile::addTransactionToFile(Transaction transaction)
{
    CMarkup xml;
    bool fileExists = xml.Load(FILE_NAME);

    if ( ! fileExists ) {
        xml.AddElem(MAIN_TAG); // main tag - FILE_NAME without extensios (e.g. incomes for incomes.xml)
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("transaction");
    xml.IntoElem();
    xml.AddElem("id", transaction.getId());
    xml.AddElem("userId", transaction.getUserId());
    xml.AddElem("date", transaction.getDate());
    xml.AddElem("category", transaction.getCategory());
    xml.AddElem("amount", transaction.getAmount());
    xml.Save(FILE_NAME);
    lastTransactionId = transaction.getId();
}

int TransactionsFile::getLastTransactionId()
{
    return lastTransactionId;
}

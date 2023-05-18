#include "TransactionsManager.h"

void TransactionsManager::addTransaction()
{
    Transaction transaction = getTransactionDataFromUser();
    transactionsFile.addTransactionToFile(transaction);
    transactions.push_back(transaction);
}

Transaction TransactionsManager::getTransactionDataFromUser()
{
    Transaction transaction;
    transaction.setId(transactionsFile.getLastTransactionId()+1);
    transaction.setUserId(LOGGED_USER_ID);

    std::string date;
    char choice = ' ';
    std::cout << "Is it today's transaction? (y/n):\n";
    std::cin >> choice;
    while (choice != 'y' && choice != 'n')
    {
        std::cout << "The choice is not valid. Choose 'y' for 'yes' or 'n' for 'no':\n";
        std::cin >> choice;
    }
    if (choice == 'y') {date = DatesHandler::getCurrentDate();}
    else {date = DatesHandler::getDateFromUser();};

    transaction.setDate(date);
    transaction.setAmount(AuxiliaryMethods::getFloatFromUser());

    std::string category;
    std::cout << "Enter category: ";
    std::cin >> category;
    transaction.setCategory(category);

    return transaction;
}

bool TransactionsManager::CompareTransactionsByDate (Transaction t1, Transaction t2)
{
    return (t1.getDate()) < (t2.getDate());
}

float TransactionsManager::getGivenPeriodTransactions(std::string startDate, std::string endDate)
{
    float transactionsSum = 0;
    std::sort (transactions.begin(), transactions.end(), CompareTransactionsByDate);

    int n = 1;
    for (int i = 0, vectorSize = transactions.size(); i < vectorSize; i++)
    {
        std::string date = transactions[i].getDate();
        if ( (startDate <= date && date <= endDate) )
        {
            std::cout << "------\n";
            std::cout << "number: " << n++ << std::endl;
            std::cout << "date: " << transactions[i].getDate() << std::endl;
            std::cout << "category: " << transactions[i].getCategory() << std::endl;
            std::cout << "amount: " << transactions[i].getAmount() << std::endl;
            transactionsSum += atof(transactions[i].getAmount().c_str());
        }

    }
    std:: cout << std::endl;

    return transactionsSum;
}

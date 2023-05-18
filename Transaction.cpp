#include "Transaction.h"

void Transaction::setId(int newId)
{
    if ( newId >= 0 )
        id = newId;
}

void Transaction::setUserId(int newUserId)
{
    userId = newUserId;
}

void Transaction::setDate(std::string newDate)
{
    date = newDate;
}

void Transaction::setCategory(std::string newCategory)
{
    category = newCategory;
}

void Transaction::setAmount(std::string newAmount)
{
    amount = newAmount;
}

int Transaction::getId()
{
    return id;
}

int Transaction::getUserId()
{
    return userId;
}

std::string Transaction::getDate() const
{
    return date;
}

std::string Transaction::getCategory()
{
    return category;
}

std::string Transaction::getAmount()
{
    return amount;
}

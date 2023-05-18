#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <vector>

class Transaction
{
    int id = 0;
    int userId = 0;
    std::string date = "";
    std::string category = "";
    std::string amount = "";

public:
    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(std::string newDate);
    void setCategory(std::string newCategory);
    void setAmount(std::string newAmount);

    int getId();
    int getUserId();
    std::string getDate() const;
    std::string getCategory();
    std::string getAmount();
};

#endif

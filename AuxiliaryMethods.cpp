#include "AuxiliaryMethods.h"

int AuxiliaryMethods::countPunctuationMarks(std::string str)
{
    std::string::iterator strBegin= str.begin();
    std::string::iterator strEnd = str.end();
    return std::count(strBegin, strEnd, ',') + std::count(strBegin, strEnd, '.');
}

std::string AuxiliaryMethods::getFloatFromUser()
{
	std::string amount = "";
    bool validFloat = false;
    while (!validFloat)
    {
        std::cout << "Enter an amount:\n";
        std::cin >> amount;
        if (amount.find_first_not_of("1234567890.,") == std::string::npos)
        {
            int len = amount.length();
            int dotPosition = 0;
            int punctuationMarksCount = countPunctuationMarks(amount);

            if (punctuationMarksCount == 0)
            {
                amount += ".";
                len += 1;
                dotPosition = len-1;
                validFloat = true;
            }

            else if (punctuationMarksCount == 1)
            {
                int i;
                for (i=0; i<len; i++)
                {
                    int ascii = int(amount[i]);
                    if (ascii == 44)
                    {
                        amount.replace(i, 1, ".");
                        break;
                    }
                    if (ascii == 46)
                    {
                        break;
                    }
                }
                dotPosition = i;
                validFloat = true;
            }

            if (validFloat)
            {
                // set precision to hundreth - append zeros or trim
                int precision = len - dotPosition;
                for (int i=2; i >= precision; i--) {amount += "0";}
                amount = amount.substr(0, dotPosition+3);

            }
        }
        if (!validFloat) {std::cout << "Invalid number. Try again:\n";}
    }
    return amount;
}

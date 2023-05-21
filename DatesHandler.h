#ifndef DATESHANDLER_H
#define DATESHANDLER_H

#include <iostream>
#include <ctime>
#include <regex>

static const std::string LOWER_LIMIT_DATE = "2000-01-01"; // must be outside the class - cant have static const strings

class DatesHandler
{

    static int getMonthDaysCount(int year, int month);
    static void printDateFormatHint(std::string lowerLimitDate=LOWER_LIMIT_DATE);
    static bool validateDate(std::string date, std::string lowerLimitDate=LOWER_LIMIT_DATE);
    static bool validateDateFormat(std::string date);
    static tm getLocalizedTime ();


public:
    static std::string getCurrentDate();
    static std::string getCurrentMonthFirstDay();
    static std::string getCurrentMonthLastDay();
    static std::string getLastMonthFirstDay();
    static std::string getLastMonthLastDay();
    static std::string getDateFromUser(std::string lowerLimitDate=LOWER_LIMIT_DATE);
};

#endif

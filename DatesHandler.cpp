#include "DatesHandler.h"

tm DatesHandler::getLocalizedTime()
{
    std::time_t currentTime = std::time(nullptr);
    struct tm localizedTime = *std::localtime(&currentTime);
    return localizedTime;
}

int DatesHandler::getMonthDaysCount(int year, int month) {
    int monthDaysCount = 0;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12: monthDaysCount = 31; break;

    case 4:
    case 6:
    case 9:
    case 11: monthDaysCount = 30; break;

    case 2:
        if ( (year % 4 == 0) && (year % 100 != 0 ) || (year % 400 == 0) )
        { monthDaysCount = 29; }
        else { monthDaysCount = 28; }
        break;
    }

    return monthDaysCount;
}

std::string DatesHandler::getCurrentDate()
{
    tm localizedTime = getLocalizedTime();
    char currentDate[11];
    strftime(currentDate, 11, "%Y-%m-%d", &localizedTime);
    return currentDate;
}


std::string DatesHandler::getCurrentMonthFirstDay()
{
    tm localizedTime = getLocalizedTime();
    localizedTime.tm_mday = 1;
    char monthFirstDay[11] = "";
    strftime(monthFirstDay, 11, "%Y-%m-%d", &localizedTime);
    return monthFirstDay;
}

std::string DatesHandler::getCurrentMonthLastDay()
{
    tm localizedTime = getLocalizedTime();
    int year = localizedTime.tm_year + 1900; // tm_year = years since 1900
    int month = localizedTime.tm_mon+1; // indexed from zero
    localizedTime.tm_mday = getMonthDaysCount(year, month);
    char monthLastDay[11] = "";
    strftime(monthLastDay, 11, "%Y-%m-%d", &localizedTime);
    return monthLastDay;
}

std::string DatesHandler::getLastMonthFirstDay()
{
    tm localizedTime = getLocalizedTime();
    localizedTime.tm_mon -= 1;
    localizedTime.tm_mday = 1;
    char monthFirstDay[11] = "";
    strftime(monthFirstDay, 11, "%Y-%m-%d", &localizedTime);
    return monthFirstDay;
}

std::string DatesHandler::getLastMonthLastDay()
{
    tm localizedTime = getLocalizedTime();
    int year = localizedTime.tm_year + 1900;
    int month = localizedTime.tm_mon;
    localizedTime.tm_mon -= 1;
    localizedTime.tm_mday = getMonthDaysCount(year, month);
    char monthLastDay[11] = "";
    strftime(monthLastDay, 11, "%Y-%m-%d", &localizedTime);
    return monthLastDay;
}

void DatesHandler::printDateFormatHint(std::string lowerLimitDate)
{
    std::cout << "Date must be in format yyyy-mm-dd. Date must be between " << lowerLimitDate << " and " << getCurrentMonthLastDay() << ":\n";
}

std::string DatesHandler::getDateFromUser(std::string lowerLimitDate)
{
    std::string date;
    do
    {
        printDateFormatHint(lowerLimitDate);
        std::cin >> date;
    } while ( ! validateDate(date, lowerLimitDate) );
    return date;
}

bool DatesHandler::validateDateFormat(std::string date)
{
    return regex_match(date, std::regex("\\d{4}-\\d{2}-\\d{2}"));
}

bool DatesHandler::validateDate(std::string date, std::string lowerLimitDate)
{
    if (validateDateFormat(date))
    {
        if (lowerLimitDate <= date && date <= getCurrentMonthLastDay())
        {
            int year = stoi(date.substr(0, 4));
            int month = stoi(date.substr(5, 2));
            int day = stoi(date.substr(8, 2));
            if ((1 <= month) && (month <= 12) && (1 <= day) && (day <= getMonthDaysCount(year, month)))
                {return true;}
        }
    }
    return false;
}

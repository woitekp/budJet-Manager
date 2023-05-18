#include "DatesHandler.h"

std::string DatesHandler::getCurrentDate()
{
    std::time_t currentTime = std::time(nullptr);
    struct tm localizedTime = *std::localtime(&currentTime);
    char currentDate[11];
    strftime(currentDate, 11, "%Y-%m-%d", &localizedTime);
    return currentDate;
}

int DatesHandler::getMonthDaysCount(int year, int month) {
    switch (month)
    {
    case 1: return 31;
    case 2:
        {
            if ( (year % 4 == 0) && (year % 100 != 0 ) || (year % 400 == 0) )
            { return 29; }
            else { return 28; }

        }
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    }
}

std::string DatesHandler::getCurrentMonthFirstDay()
{
    std::time_t currentTime = std::time(nullptr);
    struct tm localizedTime = *std::localtime(&currentTime);
    localizedTime.tm_mday = 1;
    char monthFirstDay[11] = "";
    strftime(monthFirstDay, 11, "%Y-%m-%d", &localizedTime);
    return monthFirstDay;
}

std::string DatesHandler::getCurrentMonthLastDay()
{
    std::time_t currentTime = std::time(nullptr);
    struct tm localizedTime = *std::localtime(&currentTime);
    int year = localizedTime.tm_year + 1900; // tm_year = years since 1900
    int month = localizedTime.tm_mon+1; // indexed from zero
    localizedTime.tm_mday = getMonthDaysCount(year, month);
    char monthLastDay[11] = "";
    strftime(monthLastDay, 11, "%Y-%m-%d", &localizedTime);
    return monthLastDay;
}

std::string DatesHandler::getLastMonthFirstDay()
{
    std::time_t currentTime = std::time(nullptr);
    struct tm localizedTime = *std::localtime(&currentTime);
    localizedTime.tm_mon -= 1;
    localizedTime.tm_mday = 1;
    char monthFirstDay[11] = "";
    strftime(monthFirstDay, 11, "%Y-%m-%d", &localizedTime);
    return monthFirstDay;
}

std::string DatesHandler::getLastMonthLastDay()
{
    std::time_t currentTime = std::time(nullptr);
    struct tm localizedTime = *std::localtime(&currentTime);
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

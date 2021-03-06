#include "stdio.h"
#include "time.h"
#include "stdbool.h"
#include "math.h"

void printMenu();
void showCurrentDate();
void showAllDaysForMonth();
void getWeekDayOfGivenDate();
void checkIfLeapYear();
int getDayOfTheWeek(int year, int month, int day);

int main (int argc, char *argv [])
{
    int sel = 0;
    do {
        printMenu();

        scanf("%d", &sel);

        switch (sel)
        {
        case 1:
            showCurrentDate();
            break;
        case 2:
            showAllDaysForMonth();
            break;
        case 3:
            getWeekDayOfGivenDate();
            break;
        case 4:
            checkIfLeapYear();
        default:
            break;
        }

    } while (sel != 0);

    return 0;
}

void printMenu()
{
    printf("\n\tCalendar\n\n");

    printf("1. Show current date\n");
    printf("2. Show all days of a given month in a year\n");
    printf("3. Find out the day by given date\n");
    printf("4. Check if given year is leap year\n");
    printf("0. Exit\n\n");
}

void showCurrentDate()
{
    time_t rawtime;
    time(&rawtime);

    printf(ctime(&rawtime));
}

void showAllDaysForMonth()
{
    int days[] =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, year;
    printf("Enter a month number (1-12) space separated with year: ");
    scanf("%d %d", &month, &year);

    printf("You've entered %d and %d\n", month, year);

    int d = getDayOfTheWeek(year, month, 1);

    // print 7 columns for 7 days of week using corresponding number of days
    // but first print 3 spaces according to calculated d
    int i = 1;
    while (i < d)
    {
        printf("   ");
        i++;
    }
    for (i = 1; i <= days[month - 1]; i++)
    {
        if (i < 10) printf(" ");
        printf("%d ", i);
        if ((d + i - 1) % 7 == 0) printf("\n");
    }
}

void getWeekDayOfGivenDate()
{
    int year, month, day;
    printf("Enter date in following format: [YYYY MM DD]: ");
    scanf("%d %d %d", &year, &month, &day);

    int d = getDayOfTheWeek(year, month, day);
    printf("Day of the week is %d\n", d);
}

void checkIfLeapYear()
{
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    printf("Year %d %s a leap year\n\n", year, isLeapYear ? "is" : "is not");
}

int getDayOfTheWeek(int year, int month, int day)
{
    // using Zeller's congruence algorithm to determine the day of the week
    int q = day;
    int m = month;
    if (m == 1) {
        m = 13;
        year--;
    }
    if (m == 1) {
        m = 14;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    int d = (q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    d = ((d + 5) % 7) + 1;
    return d;
}
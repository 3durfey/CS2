/* Program name: peter_durfey_m01project2.cpp
 *  Author: Peter Durfey
 *  Date last updated: 9/05/2022
 * Purpose: create date class that collects day month year
 */

#include <iostream>
using namespace std;

void validate(string month);

int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string monthN[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int returnvalue = 0;

class date
{
    public:
    int day, month, year;
    string invalidMonth = "Invalid month. There are 12 months in the year.";
    string invalidYear = "Invalid year. Must be between 1990 and 2020.";

    date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
        
        try
        {
            if (month < 1 || month > 12)
            {
                throw (invalidMonth);
            }
            if (day > months[month-1] || day < 0)
            {
                throw (day);
            }
            if (year < 1900 || year > 2020)
            {
                throw (invalidYear);
            }
        }
        catch (int q)
            {
                cout << monthN[m-1] << " " << d << ", " << y << endl;
                returnvalue = 1;
            }
        catch (string t)
        {
            cout << t << endl;
            returnvalue = 1;
        }

    }

    void toString(int d, int m, int y)
    {
        cout << monthN[m-1] << " " << d << ", " << y << endl;
    }
    int setDay(int d, int m)
    {
        day = d;
        int returnvalue = 0;
        try
        {
            if (day > months[month] || day < 0)
            {
                throw (day);
            }
        }
        catch (int monthA)
            {
                cout << "Invalid entry." << monthN[m-1] << " has " << months[m] << " days" << endl;
            }
        return returnvalue;
    }
    int setMonth(int m)
    {
        month = m;
        int returnvalue = 0;
        try
        {
            if (month < 1 || month > 12)
            {
                throw (month);
            }
        }
        catch (int e)
            {
                cout << invalidMonth << endl;
            }
        return returnvalue;
    }
    int setYear(int y)
    {
        year = y;
        int returnvalue = 0;
        try
        {
            if (year < 1900 || year > 2020)
            {
                throw (invalidYear);
            }
        }
        catch (string f)
        {
            cout << invalidYear << endl;
            returnvalue = 1;
        }
        return returnvalue;
    }
};

int main()

{
    int day, month, year;

    cout << "Enter day in the form Month/Day/Year: ";
    while(!(cin >> month))
    {
        validate("entire date");
    }
    cin.ignore(1); 
    while(!(cin >> day))
    {
        validate("day and year");
    }
    cin.ignore(1);
    while(!(cin >> year))
    {
        validate("year");
    }
    date userdate(day, month, year);
    if (returnvalue = 0)
    {
    userdate.toString(day, month, year);
    returnvalue = 1;
    }

    do {
    cout << "Enter new date in the format Month/Day/Year: ";
    while(!(cin >> month))
    {
        validate("entire date");
    }
    cin.ignore(1); 
    while(!(cin >> day))
    {
        validate("day and year");
    }
    cin.ignore(1);
    while(!(cin >> year))
    {
        validate("year");
    }
    returnvalue = userdate.setDay(day, month);
    returnvalue = userdate.setMonth(month);
    returnvalue = userdate.setYear(year);

    } while (returnvalue == 1);
    userdate.toString(day, month, year);

}

void validate(string month)
{
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Re-enter " << month << ": ";
}


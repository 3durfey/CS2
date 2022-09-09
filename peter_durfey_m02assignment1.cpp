/* Program name: peter_durfey_m01project2.cpp
 *  Author: Peter Durfey
 *  Date last updated: 9/05/2022
 * Purpose: create date class that collects day month year
 */

#include <iostream>
using namespace std;
//create validation function for input
void validate(string month);
//make variables for months and return variable
static int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string monthN[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int returnvalue = 0;
//declare class
class date
{
//create variables for exceptions
    public:
    int day, month, year;
    string invalidMonth = "Invalid month. There are 12 months in the year.";
    string invalidYear = "Invalid year. Must be between 1990 and 2020.";
//create constructor and try catch exceptions
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
            if (day > months[month-1] || day <= 0)
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
                returnvalue = 1;
                if (m < 0 || m <= 12 && m != 0)
                {
                cout << "Invalid entry. " << monthN[m-1] << " has " << months[m-1] << " days" << endl;
                }
                else 
                {
                    cout << "Invalid day, month does not exist." << endl;
                }                
            }
        catch (string t)
        {
            cout << t << endl;
            returnvalue = 1;
        }

    }
//create function to output date
    void toString(int d, int m, int y)
    {
        cout << monthN[m-1] << " " << d << ", " << y << endl;
    }
//create mutators for day month and year
    int setDay(int d, int m)
    {
        day = d;
        try
        {
            if (day > months[month] || day <= 0)
            {
                throw (day);
                returnvalue = 1;
            }
        }
        catch (int monthA)
            {
                returnvalue = 1;
                if (m < 0 || m <= 12 && m != 0)
                {
                    cout << "Invalid entry. " << monthN[m-1] << " has " << months[m-1] << " days" << endl;
                }
                else 
                {
                    cout << "Invalid day, month does not exist." << endl;
                }
            }
        return returnvalue;
    }
    int setMonth(int m)
    {
        month = m;
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
                returnvalue = 1;
            }
        return returnvalue;
    }
    int setYear(int y)
    {
        year = y;
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
//create variables for day month year
    int day, month, year;
//create point to retry entry if invalid
    retry:
    returnvalue = 0;
//get input and validate
    cout << "Enter date in the form Month/Day/Year: ";
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
//create object
    date userdate(day, month, year);
    if (returnvalue == 1)
    {
        goto retry;
    }
//output date
    cout << "Date entered: ";
    userdate.toString(day, month, year);
//update date using mutator methods and do/while loop till valid
    do {
    returnvalue = 0;
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
//output modified date
    cout << "Modified date: ";
    userdate.toString(day, month, year);

}
//validator method
void validate(string month)
{
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Re-enter " << month << ": ";
}



/* Program name: peter_durfey_m01project2.cpp
 *  Author: Peter Durfey
 *  Date last updated: 9/05/2022
 * Purpose: create date class that collects day month year
 */

#include <iostream>
using namespace std;

void validate(string month);

class date
{
    int day, month, year;
  
    public:
        date(int d, int m, int y)
        {
            day = d;
            month = m;
            year = y;
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
    







}









void validate(string month)
{
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(500, '\n');
        cout << "Re-enter " << month << ": ";
}
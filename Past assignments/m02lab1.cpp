/* Program name: m02lecturelabactivity.cpp
*  Author: Peter Durfey
*  Date last updated: 9/01/2022
* Purpose: Write a program to ask the user for a first name.  
* Then take that value (variable) into a try-catch and test it for being alphabetic.  
* If not alphabetic, tell the user the problem and ask for the name again.
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int v = 0;

do {
    cout << "Enter first name: ";
    cin >> name;
    for(int x =  0; x < name.length(); x++)
    {

        if (!isalpha(name[x]))
        {
            v = 1;
            break;
        }
    }

    try 
    {
        if (v == 1)
        {
            throw (v);
        }
    }
    catch (int y)
    {
        cout << "Invalid name" << endl;
    }

    } while (v == 1);
    
}
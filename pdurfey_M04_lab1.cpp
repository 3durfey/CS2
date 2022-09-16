/* Program name: m02lecturelabactivity.cpp
*  Author: Peter Durfey
*  Date last updated: 9/01/2022
* Purpose: create a loop program 
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    do
    {
        cout << "Enter number: ";
        cin >> num;
        if (num > 30)
        {
            cout << num << endl;
            break;
        }
    } while (num < 10);
}
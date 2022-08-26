/* Program name: peter_durfey_m01lab2.cpp
*  Author: Peter Durfey
*  Date last updated: 8/27/2022
* Purpose: basic function with classes
*/

#include <iostream>
using namespace std;

void funct(int x, string y);
int a = 4;
string b = "string";

int main()
{
     
    funct(a, b);
    cout << a << " " << b <<  endl;

}

void funct(int x, string y)
{
    cout << x << " " << y << endl;
    x = 5;
    y = "string2";
    cout << x << " " << y << endl;
    return;
}

//the values passed into the function changed because they were changed in the function. The origional functions in main did not change because they were only modified in the function.
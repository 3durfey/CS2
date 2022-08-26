/* Program name: peter_durfey_m01lab2.cpp
*  Author: Peter Durfey
*  Date last updated: 8/27/2022
* Purpose: basic function with classes
*/

#include <iostream>
using namespace std;

class dog
{
    public:
    string color, breed;
    double weight;
    int age;
    dog()
    {
        color = "white/brown";
        breed = "beagle";
        weight = 45;
        age = 7;
    }
};

class cat
{
    public:
    string color, breed;
    double weight;
    int age;
    cat(string c, string b, double w, int a)
    {
        color = c;
        breed = b;
        weight = w;
        age = a;
    }
};

int main()
{
    string color, breed;
    double weight;
    int age;
    cout << "Enter the cat's color: ";
    cin >> color;
    cout << "Enter cat's breed: ";
    cin >> breed;
    cout << "Enter cat's weight: ";
    cin >> weight;
    cout << "Enter cat's age: ";
    cin >> age;

    cat cat(color, breed, weight, age);
    dog dog();
    cout << cat.color << endl;

return 0;
}




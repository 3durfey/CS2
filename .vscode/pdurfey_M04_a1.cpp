/* Program name: pdurfey_M04_a1.cpp
*  Author: Peter Durfey
*  Date last updated: 9/16/2022
* Purpose:  develop a class for soldiers in the Army
*/

#include <iostream>
using namespace std;
string ranks[10] = {"private", "specialist", "corporal", "sergeant", "officer", "lieutenant", "captain", "major", "colonel", "general"};

class soldiers
{
    string name;
    string rank;
    string classification;

    public:
    soldiers(string name, string rank, string classification)
    {
        this->name;
        this->rank;
    }
    
};
int main()
{
    string name; 
    string rank;
    cout << "Enter full name: ";
    getline (cin, name);
    cout << name << endl;
    cout << "enter rank:";
    getline (cin, rank);
    cout << rank;
}
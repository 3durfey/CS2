/* Program name: pdurfey_M04_a1.cpp
*  Author: Peter Durfey
*  Date last updated: 9/16/2022
* Purpose:  develop a class for soldiers in the Army
*/

#include <iostream>
#include <vector>
using namespace std;
string ranks[10] = {"private", "specialist", "corporal", "sergeant", "officer", "lieutenant", "captain", "major", "colonel", "general"};
void validate();

class soldiers
{
    public:
    string name;
    string rank;
    string classification;

    public:
    soldiers(string name, string rank)
    {
        try
        {
            this->name = name;
            this->check_rank(rank);
        }       
        catch (invalid_argument msg)
        {
                cout << msg.what();
        }
    }
    
    void check_rank(string m)
    {
        int found = 0;
        for (int x = 0; x < 10; x++)
        {
            if (m == ranks[x])
            {
                this->rank = m;
                found = 1;
            }
        }
        if (found != 1)
        {
            throw invalid_argument("Invalid rank");
        }
    }
};
vector<soldiers> soldier_list;

int main()
{
    int num;
    vector<soldiers> soldier_list;
    cout << "Enter number of soldiers to be entered: ";
    while (!(cin >> num))
    {
        validate();
    }

    for(int x = 0; x < num; x++)
    {
        string name, rank;
        cout << "Enter full name: ";
        getline(cin, name);

        while (!cin)
        {
            cout << "invalid input\n";
            cin.clear();
            cout << "re-enter: ";
            getline(cin, name);
        }

        cout << "enter rank:";
        cin.ignore();
        getline(cin, rank);
        while (!cin)
        {
            cout << "invalid input\n";
            cin.clear();
            cout << "re-enter: ";
            getline(cin, rank);
        }
        soldier_list.push_back (soldiers(name, rank));
    }

}
void validate()
{
    cout << "Invalid input\n";
    cin.clear();
    cout << "Re-Enter: ";
}
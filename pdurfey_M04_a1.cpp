/* Program name: pdurfey_M04_a1.cpp
*  Author: Peter Durfey
*  Date last updated: 9/16/2022
* Purpose:  develop a class for soldiers in the Army
*/

#include <iostream>
#include <vector>
using namespace std;
double salary_list[10] = {1833, 2500, 2500, 2500, 8333, 5833, 4166, 7500, 8333, 16975};
string ranks[10] = {"private", "specialist", "corporal", "sergeant", "officer", "lieutenant", "captain", "major", "colonel", "general"};
void validate();
int num;

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
            this->set_class(rank);
        }       
        catch (invalid_argument msg)
        {
                cout << msg.what() << endl;
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
    void set_class(string r)
    {
        int m;
        for (int x = 0; x < 10; x++)
        {
            if (r == ranks[x])
            {
                m = x + 1;
            }
        }
        if (m <= 2)
        {
            classification = "enlisted";
        }
        else if (m == 5)
        {
            classification = "warrant";
        }
        else 
        {
            classification = "officer";
        }
    }
    double pay(string r)
    {
            int m;
            double d;
            for (int x = 0; x < 10; x++)
            {
                if (r == ranks[x])
                {
                    m = x;
                }
            }
            d = salary_list[m];
            return d;
    }
    string toString()
    {
        string m = name + " " + rank + " " + classification;
        return m;
    }
};
vector<soldiers> soldier_list;

int main()
{
    string name, soldier_rank;
    vector<soldiers> soldier_list;
    //get number of soldiers to be entered
    cout << "Enter number of soldiers to be entered: ";
    while (!(cin >> num) || num > 7)
    {
        validate();
    }
    cin.ignore();
    //loop for amount of soldiers
    for(int x = 0; x < num; x++)
    {
        //get name
        cout << "Enter full name: ";
        getline(cin, name);
        //get rank
        cout << "enter rank:";
        getline(cin, soldier_rank);
        //add soldier to vector
        soldier_list.push_back (soldiers(name, soldier_rank));
    }
    string r = soldier_list[0].toString();
    cout << r << endl;

}
void validate()
{
    cout << "Invalid input\n";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Re-Enter: ";
}
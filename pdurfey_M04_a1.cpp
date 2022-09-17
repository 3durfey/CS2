/* Program name: pdurfey_M04_a1.cpp
*  Author: Peter Durfey
*  Date last updated: 9/16/2022
* Purpose:  develop a class for soldiers in the Army
*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
//arrays for ranks and salary
double salary_list[10] = {1833, 2500, 2500, 2500, 8333, 5833, 4166, 7500, 8333, 16975};
string ranks[10] = {"private", "specialist", "corporal", "sergeant", "officer", "lieutenant", "captain", "major", "colonel", "general"};
//functions
void validate();
string highest_rank();
//int for number of soldiers
int num;

class soldiers
{
    private:
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
    bool operator == (soldiers s1)
    {
        if (rank == s1.rank)
        {
            return true;
        }
        return false;
    }
    string operator > (soldiers s1)
    {
        int rank1, rank2;
        for(int x = 0; x < 10; x++)
        {
            if (rank == ranks[x])
            {
                rank1 = x;
            }
            else if (s1.name == ranks[x])
            {
                rank2 = x;
            }
        }
        if (rank1 < rank2)
        {
            return name;
        }
        else 
        {
            return s1.name;
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
    double get_pay(string r)
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
    string get_name()
    {
        return this->name;
    }
    string get_rank()
    {
        return this->rank;
    }
};
vector<soldiers> soldier_list;

int main()
{
    string name, soldier_rank;
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

    //list all soldiers
    cout << "List of all soldiers: " << endl;
    for(int x = 0; x < soldier_list.size(); x++)
    {
        cout << soldier_list[x].toString() << endl;
    }
    //highest ranking soldier entered
    string highest = highest_rank();
    cout << highest << endl;

    //create random number generator based on number of soldiers to randomly change ranks
    srand(time(0));
    int random = rand();

}
void validate()
{
    cout << "Invalid input\n";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Re-Enter: ";
}
string highest_rank()
{
    string highest_rank;
    int y = 0;
    for(int x = 0; x < soldier_list.size(); x++)
        {
            string temp_name = soldier_list[y] > soldier_list[x];
            if (temp_name != highest_rank)
            {
                highest_rank = temp_name;
                y = x;
            }
        }
        return highest_rank;
}

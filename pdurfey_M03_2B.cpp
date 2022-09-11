/* Program name: pdurfey_M03_2B.cpp
*  Author: Peter Durfey
*  Date last updated: 9/01/2022
* Purpose: Write a program that reads words from a text file and displays all the non-duplicate words
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
vector<string> abb, full, gov, flower;
int validate(string abbrev);

struct state_info
{
    string full_name;
    string governor;
    string flower;
};

int main ()
{
    //open file return 1 if unable to do so
    ifstream file;

    file.open ("sample.txt");
    if (!file.is_open()) return 1;
    //temp for words in file
    string word;
    //insert into struct
    while (file >> word)
    {
        abb.push_back(word);
        file >> word;
        full.push_back(word);
        file >> word;
        gov.push_back(word);
        file >> word;
        gov.push_back(word);
        file >> word;
        flower.push_back(word);        
    }

    map<string, state_info> states;
    state_info array_info[50];
    int x, y = 0;
    for (auto i = abb.begin(); i != abb.end(); ++i)
    {
        array_info[x].full_name = full[x];
        array_info[x].governor = gov[y]+" "+gov[y+1];
        array_info[x].flower = flower[x];

        states.insert(pair<string, state_info>(*i, array_info[x]));
        x++, y+=2;
    }

    string state, sentinal;
    do
    {
    cout << "Enter desired state abreviation: ";
    while(!(cin >> state) || validate(state) == 1)
    {
        cout << "Invalid state abbreviation, must be uppercase as well as valid state abbreviation: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Re-Enter: ";
    }

    cout << "Full name of state: "<< states[state].full_name << endl;
    cout << "Name of Governor: "<<states[state].governor << endl;
    cout << "State Flower: "<< states[state].flower << endl;
    cout << "Press any key + Enter to enter another abbreviation or x + Enter to exit: ";
    cin >> sentinal;

    }while(sentinal != "x");


}
int validate(string abbrev)
{
    for (auto i = abb.begin(); i != abb.end(); ++i)
    {
        if (abbrev == *i)
        {
            return 0;
        }
    }
    return 1;
}

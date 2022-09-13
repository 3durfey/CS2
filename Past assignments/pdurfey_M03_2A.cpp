/* Program name: pdurfey_M03_2A.cpp
*  Author: Peter Durfey
*  Date last updated: 9/01/2022
* Purpose: Write a program that reads words from a text file and displays all the non-duplicate words
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
int main ()
{
    set<string> non_duplicate;
    vector<string> vectorstring;
    ifstream file;
    
    file.open ("txt.txt");
    if (!file.is_open()) return 1;

    string word;
    while (file >> word)
    {
        vectorstring.push_back(word);
    }
    for (int x = 0; x < vectorstring.size(); x++)
    {
        int repeat = 0;
        for (int y = 0; y < vectorstring.size(); y++)
        {
            if (vectorstring[x] == vectorstring[y])
            {
                repeat++;
            }
            if (repeat > 1)
            {
                break;
            }
        }
        if (repeat < 2)
        {
            non_duplicate.insert (vectorstring[x]);
        }
    }
    cout << "List of non-repeating words: ";
    for (auto x = non_duplicate.begin(); x !=non_duplicate.end(); x++)
    {
        cout << *x << " ";
    }
    cout << endl;
}
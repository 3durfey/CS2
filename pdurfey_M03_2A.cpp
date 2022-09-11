/* Program name: pdurfey_M03_2A.cpp
*  Author: Peter Durfey
*  Date last updated: 9/01/2022
* Purpose: Write a program that reads words from a text file and displays all the non-duplicate words
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <iterator>    
#include <algorithm>

using namespace std;
int main ()
{
    //create data types
    set<string> non_duplicate;
    vector<string> vectorstring;
    vector<string>::iterator it;

    ifstream file;
    //open file return 1 if can't be opened
    file.open ("txt.txt");
    if (!file.is_open()) return 1;
    //make variable for word
    string word;
    //take words one at a time from file and add to vector/
    while (file >> word)
    {
        vectorstring.push_back(word);
    }
    //check vector from repeats and add to set if not
    do
    {
        string temp = vectorstring[0];
        vectorstring.erase(vectorstring.begin());
        bool duplicate = 0;
        if (vectorstring.size()  == 0)
        {
            non_duplicate.insert (temp);
            break;
        }
        check:
        it = find(vectorstring.begin(), vectorstring.end(), temp);
        if (*it != temp && duplicate != 1)
        {
            non_duplicate.insert (temp);
        }
        else if (*it == temp)
        {
            vectorstring.erase(it);
            duplicate = 1;
            goto check;
        }
    } while (!vectorstring.empty());

    //output results
    cout << "List of non-repeating words: ";
    for (auto x = non_duplicate.begin(); x !=non_duplicate.end(); x++)
    {
        cout << *x << " ";
    }
    cout << endl;
}
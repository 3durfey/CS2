/* Program name: pdurfey_M03_2A.cpp
*  Author: Peter Durfey
*  Date last updated: 9/01/2022
* Purpose: Write a program that reads words from a text file and displays all the non-duplicate words
*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
void openFile(ifstream&, string);
int main ()
{
    ifstream inFile;
    openFile(inFile, "sample.txt");

    
}
void opeFile(ifstream& inFile, string fname)
{
    inFile.open(fname);
    if(inFile.is_open())
    {
        cout << "successfully opened file"<< endl;
    }
    else
    {
        cout << "failure to open file" << endl;
        exit(-1);
    }

}
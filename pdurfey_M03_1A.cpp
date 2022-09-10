/* Program name: pdurfey_M03_1A.cpp
*  Author: Peter Durfey
*  Date last updated: 9/01/2022
* Purpose: Write a modular program that analyzes a student’s quiz scores (0-15). 
*/

#include <iostream>
#include <vector>
using namespace std;
void validate();

template <typename T> class getData
{
    T* ptr_grades;
    int size;
    T low_score;
    T high_score;
public:
    getData(int size);
    void print();
    vector<T> lowScore();
    vector<T> highScore();
    T average();
};


template <typename T> getData<T>::getData(int s)
{
        ptr_grades = new T[s];
        size = s;
        for (int x = 0; x < s; x++)
        {
        cout << "Enter quiz score for week " << x + 1 << endl;
            while(!(cin >> ptr_grades[x]) || ptr_grades[x] < 0 || ptr_grades[x] > 15)
            {
                validate();
            }
        }
}
template <typename T> void getData<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << "Module " << i + 1 << ": " << ptr_grades[i] << endl;
}
template <typename T> T getData<T>::average()
{
    T average;
    for (int x = 0; x < size; x++)
    {
        average+=ptr_grades[x];
    }
    average = average/size;
    return average;
}
template <typename T> vector<T> getData<T>::lowScore()
{
    vector<T> low_score;
    T ls = ptr_grades[0];
    for (int x = 1; x < size; x++)
    {
        if (ptr_grades[x] < ls)
        {
            ls = ptr_grades[x];
        }
    }
    low_score.push_back (ls);
    for (int y = 0; y < size; y++)
    {
        if (ptr_grades[y] == ls)
        {
            low_score.push_back (y + 1);
        }
    }
    return low_score;
}
template <typename T> vector<T> getData<T>::highScore()
{
    vector<T> high_score;
    T hs = ptr_grades[0];
    for (int x = 1; x < size; x++)
    {
        if (ptr_grades[x] > hs)
        {
            hs = ptr_grades[x];
        }
    }
    high_score.push_back (hs);
    for (int y = 0; y < size; y++)
    {
        if (ptr_grades[y] == hs)
        {
            high_score.push_back (y + 1);
        }
    }
    return high_score;
}

int main()
{

//intro
    cout << "This program will determine the module with the highest and lowest scores." << endl;
    getData<double> student_scores(16);
//print all the grades per module
    cout << "Fall Quiz Grades:" << endl;
    student_scores.print();
//print out the average score
    double average = student_scores.average();
    cout << "Average Grade: " << average << endl;
//print out the low scores
    vector<double> low_score = student_scores.lowScore();
    cout << "The low score/scores occured in Module/Modules ";
    for (int x = 1; x < low_score.size(); x++)
    {
        cout << low_score[x] << " ";
    }
    cout << "with " << low_score[0] << "." << endl;
//print out the high scores
    vector<double> high_score = student_scores.highScore();
    cout << "The high score/scores occured in Module/Modules ";
    for (int y = 1; y < high_score.size(); y++)
    {
        cout << high_score[y] << " ";
    }
    cout << "with " << high_score[0] << "." << endl;


    
}

void validate()
{
    cout << "Invalid input, must be an integer between 0 and 15\n";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Re-Enter: ";
}
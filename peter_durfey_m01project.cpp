/* Program name: peter_durfey_m01project.cpp
*  Author: Peter Durfey
*  Date last updated: 8/25/2022
* Purpose: basic function
*/

#include <iostream>
using namespace std;

class Cube 
{
    int length, width, height;
    string color;

    Cube(int x, int y, int q, string f) 
    {
        length = x;
        width = y;
        height = q;
        color = f;
    }
    public:
    //accessor
    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    string getColor()
    {
        return color;
    }
    //mutators
    void setLength(int l)
    {
        length = l; 
    }
    void setHeight(int h)
    {
        height = h;
    }
    void setColor(string c)
    {
        color = c;
    }
    //volume= length*height
    int calculateVolume(int l, int h, int c)
    {
        return (l * h * c);
    }

};

int main() 
{
    double length, width, height;
    string color;
    cout<<"Enter cube length: ";
    cin>>length;
    while(!(cin >> length))
    {
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Re-Enter length: ";
    }
    cout<<length<<endl;
return 0;
}



